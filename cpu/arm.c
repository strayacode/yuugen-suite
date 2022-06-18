#include "../common/testing.h"
#include "arm.h"

void test_arm_data_processing() {
    TESTCASE("Test arm add") {
        int output = 0;

        asm(
            "mov %0, #7\n"
            "add %0, #8\n"
            : "=r" (output)
        );

        expect_eq(output, 14);
    }
}