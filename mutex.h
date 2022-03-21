/******** DO NOT EDIT THIS FILE ********/
#ifndef _MUTEX_H
#define _MUTEX_H
#include "ipc.h"
#include "proc.h"

/* 
 * Introduction
 * 
 * This header file defines a mutex type and its interface:
 *      mutex_new - to create a new mutex object
 *      mutex_enter - to acquire a mutex
 *      mutex_leave - to release a mutex
 *      mutex_delete - to delete a mutex created by mutex_new and free resources
 *
 * Current, concrete implementations of the interface are in:
 * mutex_noop.c, mutex_lockvar.c and mutex_peterson.c
 *
 * They use busy waiting to attempt to only allow acquisition of a mutex by 
 * one process at a time. A process uses mutex_enter to wait to 
 * acquire a mutex and, having acquired it, enters its critical region. 
 * When the process leaves its critical region, it calls mutex_leave to release 
 * the mutex and to allow another process to acquire it and enter their
 * critical region.
 * For a correct solution to mutual exclusion, while a mutex is acquired by one
 * process, any other process that calls mutex_enter should wait until the mutex
 * is released.
 *
 * The concrete implementations demonstrate different approaches to mutual
 * exclusion using busy waiting. They are for demonstration purposes and not 
 * necessarily correct and, therefore, demonstrate correct and incorrect
 * solutions.
 *
 * IMPORTANT:
 * Only operate on a mutex using the functions defined in 
 * this file. Using a mutex in any other way can result in undefined 
 * and erroneous behaviour.
 *
 * See documentation of mutex_enter and bwait_consumer.c and bwait_producer.c
 * for example usage of a mutex.
 */
 
 
/* 
 * Type alias to define the mutex_t type as an alias for ipc_t.
 *
 * This means that the object used for mutual exclusion is expected to 
 * be allocated in shared memory, accessible by multiple processes via the 
 * addr field of the ipc_t object.
 *
 * Different solutions to mutual exclusion will allocate different types of 
 * underlying object in shared memory. The ipc object encapsulates
 * the underlying mutex type.
 *
 * See: ipc.h, mutex_noop.h, mutex_lockvar.h, mutex_peterson.h
 */
typedef ipc_t mutex_t;

/*
 * mutex_new(proc_t* proc)
 * 
 * Creates a new mutex (allocating resources for the mutex).
 *
 * Concrete implementations of a mutex (noop, lockvar and peterson) will 
 * create a suitable mutex that is owned by the process identified by the 
 * given process descriptor.
 *
 * See mutex_enter for usage.
 *
 * Parameters:
 * proc - the non-null descriptor of a process sharing this mutex
 *
 * Return:
 * On success: a well-formed ipc object that encapsulates this mutex, 
 *      typically in shared memory. If proc is the init process and the 
 *      mutex is in shared memory, all bytes of the shared memory 
 *      object are initialised to 0. The shared memory mutex object is 
 *      accessed via the addr field of the returned object.
 * On failure: NULL, and errno is set as specified in Errors.
 *
 * Errors:
 * If the call fails, the NULL pointer will be returned and errno will be 
 * set as follows:
 *      EINVAL - invalid argument if proc is NULL
 *      Other values as specified by the system library functions used to
 *      implement the function (see ipc_new in ipc.h)
 *
 * See also:
 * proc.h - for a description of the proc type
 * ipc.h - for the ipc type for which the mutex is an alias
 * Concrete implementations of mutex_noop, mutex_lockvar and 
 * mutex_peterson
 */
mutex_t* mutex_new(proc_t* proc);


/*
 * mutex_enter(mutex_t* mux)
 * 
 * Function to acquire a mutex before entering a critical region. 
 * The mutex should only ever be in one of two states: 
 * - acquired by a process (in which case that process is in their critical 
 *      region), or
 * - available (in which case no process sharing the mutex is in 
 *      its critical region).
 * 
 * When mutex_enter is called:
 *  - if the mutex is currently acquired by another process, the caller 
 *      will busy wait until the mutex is available and then acquire it. 
 *      The function returns when the mutex is acquired by the calling process.
 *  - if the mutex is available, the calling process acquires the mutex, 
 *      the state of the mutex is changed to acquired (as appropriate to 
 *      the specific implementation) and the function returns.
 *
 * Important Note:
 * This function is not guaranteed to be reentrant. That is, an application
 * process that calls mutex_enter on a mutex that they have already acquired 
 * may wait indefinitely. mutex_leave must be called before calling mutex_enter
 * again. 
 *
 * Usage:
 *      mutex_t* mux = (mutex_t*) mutex_new(proc);
 *      if (!mux) exit(1);
 *      ...
 *      ...
 *      while (work_to_do) {
 *          mutex_enter(mux);
 *          // do critical work
 *          mutex_leave(mux);
 *          // do non critical work
 *      }
 *      ...
 *      ...
 *      mutex_delete(mux);
 *
 * Parameters:
 * mux - a non-null pointer to the mutex to acquire
 *
 * Return:
 * There is no return value for the function. If mux is not NULL and the call
 * succeeds, the mutex is acquired.
 *
 * Errors:
 * If mux is NULL, this function has no effect and will simply return. In this 
 * case the integrity of the overall application may be compromised. It is up
 * to application programmer to ensure that mux is not NULL.
 * Various errors with access to any underlying shared memory object may occur
 * in which case the process is likely to terminate with a memory error.
 *
 * See also:
 * mutex_noop.h, mutex_lockvar.h and mutex_peterson.h for information specific
 * to different mutex implementations.
 * ipc.h - for information about the ipc type
 */
void mutex_enter(mutex_t* mux);

/* 
 * mutex_leave(mutex_t* mux)
 * 
 * Function to release a previously acquired mutex on leaving a critical 
 * region. After the function returns, the mutex will be available for other 
 * processes to acquire.
 *
 * Important Note:
 * An application process calling mutex_leave on a mutex that they have
 * not previously acquired may undermine the integrity of the application.
 * mutex_leave must only be called by a process that has previously called
 * mutex_enter and acquired the mutex. See mutex_enter for usage.
 *
 * Parameters:
 * mux - a non-null pointer to the mutex to release
 *
 * Return:
 * There is no return value for the function. If mux is not NULL and the call
 * succeeds, the mutex is released.
 *
 * Errors:
 * If mux is NULL, this function has no effect and will simply return. In this 
 * case the integrity of the overall application may be compromised. It is up
 * to application programmer to ensure that mux is not NULL.
 * Various errors with access to any underlying shared memory object may occur
 * in which case the process is likely to terminate with a memory error.
 *
 * See also:
 * mutex_noop.h, mutex_lockvar.h and mutex_peterson.h for information specific
 * to different mutex implementations.
 * ipc.h - for information about the ipc type
 */
void mutex_leave(mutex_t* mux);

/*
 * mutex_delete(mutex_t* mux)
 * 
 * Deletes a mutex, deallocating resources associated with the mutex.
 * 
 * Concrete implementations of a mutex (noop, lockvar and peterson) will 
 * do what is necessary to free resources for the given mutex.
 *
 * Parameters:
 * mux - a non-null pointer to the mutex to delete
 *
 * Return:
 * There is no return value for the function. If mux is not NULL and the call 
 * succeeds, resources associated with the mutex have been freed. If mux is 
 * NULL this function has no effect.
 *
 * Errors:
 * Various errors with access to any underlying shared memory object may occur
 * in which case the process is likely to terminate with a memory error.
 */
void mutex_delete(mutex_t* mux);

#endif