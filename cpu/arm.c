#include "../common/testing.h"
#include "arm.h"

define_test(test_arm_mov) {
    int output = 0;

    asm(
        "mov %0, #7\n"
        : "=r" (output)
    );

    expect_eq(output, 7);
}

define_test(test_arm_add) {
    int output = 0;

    asm(
        "mov %0, #7\n"
        "add %0, #8\n"
        : "=r" (output)
    );

    expect_eq(output, 15);
}