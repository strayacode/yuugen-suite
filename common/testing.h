#pragma once

#include <stdio.h>

#define TESTCASE(testname)      \
    const char *test = testname;   \

#define expect_eq(expected, actual) if (expected != actual) printf("%s failed\na == b expected\nexpected: %08x\nactual: %08x\n", test, expected, actual);     