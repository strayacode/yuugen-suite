#include <stdbool.h>
#include "testing.h"

int tests_ran = 0;
int tests_failed = 0;
bool test_finished = false;

void start_test() {
    test_finished = false;
}

void fail_test() {
    if (!test_finished) {
        tests_failed++;
        test_finished = true;
    }
}

void finish_test() {
    tests_ran++;
    test_finished = true;
}

int get_tests_ran() {
    return tests_ran;
}

int get_test_finished() {
    return test_finished;
}

int get_tests_failed() {
    return tests_failed;
}