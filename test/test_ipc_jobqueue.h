/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_ipc_jobqueue.h - structures and function declarations for unit tests
 * of ipc_jobqueue functions.
 */  
#ifndef _TEST_IPC_JOBQUEUE_H
#define _TEST_IPC_JOBQUEUE_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit/munit.h"

MunitResult test_ipc_jobqueue_capacity(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_capacity_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_dequeue_fullq(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_dequeue_inout(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_dequeue_emptyq(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_dequeue_heap(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_dequeue_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_enqueue_tofull(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_enqueue_inout(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_enqueue_fullq(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_enqueue_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_is_empty(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_is_empty_notempty(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_is_empty_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_is_full_empty(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_is_full_filling(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_is_full_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_peekhead_empty(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peekhead_full(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peekhead_heap(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peekhead_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_peektail_empty(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peektail_full(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peektail_heap(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peektail_wrap(const MunitParameter params[], 
    void* fixture);
MunitResult test_ipc_jobqueue_peektail_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_ipc_jobqueue_delete(const MunitParameter params[], 
    void* fixture);

void* test_setup(const MunitParameter params[], void* user_data);
void test_tear_down(void* fixture);

static MunitTest tests[] = {
    { "/test_ipc_jobqueue_capacity", test_ipc_jobqueue_capacity, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_capacity_null", test_ipc_jobqueue_capacity_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_ipc_jobqueue_dequeue_fullq", test_ipc_jobqueue_dequeue_fullq,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_dequeue_inout", test_ipc_jobqueue_dequeue_inout,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_dequeue_emptyq", test_ipc_jobqueue_dequeue_emptyq,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_dequeue_heap", test_ipc_jobqueue_dequeue_heap,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_dequeue_null", test_ipc_jobqueue_dequeue_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_ipc_jobqueue_enqueue_tofull", test_ipc_jobqueue_enqueue_tofull,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_enqueue_inout", test_ipc_jobqueue_enqueue_inout,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_enqueue_fullq", test_ipc_jobqueue_enqueue_fullq,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_enqueue_null", test_ipc_jobqueue_enqueue_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },

    { "/test_ipc_jobqueue_is_empty", test_ipc_jobqueue_is_empty, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_is_empty_notempty",
        test_ipc_jobqueue_is_empty_notempty, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_is_empty_null",
        test_ipc_jobqueue_is_empty_null, test_setup, test_tear_down,
        MUNIT_TEST_OPTION_NONE, NULL },

    { "/test_ipc_jobqueue_is_full_empty", test_ipc_jobqueue_is_full_empty,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_is_full_filling", test_ipc_jobqueue_is_full_filling,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_is_full_null", test_ipc_jobqueue_is_full_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },

    { "/test_ipc_jobqueue_peekhead_empty", test_ipc_jobqueue_peekhead_empty,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peekhead_full", test_ipc_jobqueue_peekhead_full,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peekhead_heap", test_ipc_jobqueue_peekhead_heap,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peekhead_null", test_ipc_jobqueue_peekhead_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },

    { "/test_ipc_jobqueue_peektail_empty", test_ipc_jobqueue_peektail_empty,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peektail_full", test_ipc_jobqueue_peektail_full,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peektail_heap", test_ipc_jobqueue_peektail_heap,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peektail_wrap", test_ipc_jobqueue_peektail_wrap,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_ipc_jobqueue_peektail_null", test_ipc_jobqueue_peektail_null,
        test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },

    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_ipc_jobqueue", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif