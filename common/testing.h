#pragma once

#include <stdio.h>
#include "video.h"

void start_test();
void fail_test();
void finish_test();
int get_tests_ran();
int get_test_finished();
int get_tests_failed();

#define define_test(testname) void testname(const char *test)
#define run_test(testname) start_test(); testname(#testname); finish_test()

#define expect_eq(actual, expected) restore_vramcnt(); if (expected != actual && !get_test_finished()) { printf("%s failed\na == b expected\nexpected: %08x\nactual: %08x\n", test, expected, actual); fail_test(); }