#include "../common/testing.h"
#include "../common/types.h"
#include "arm.h"

define_test(test_arm_mov) {
    u32 output = 0;

    asm(
        "mov %0, #7\n"
        : "=r" (output)
    );

    expect_eq(output, 7);
}

define_test(test_arm_mvn) {
    u32 output = 0;

    asm(
        "mvn %0, #0\n"
        : "=r" (output)
    );

    expect_eq(output, 0xFFFFFFFF);
}

define_test(test_arm_and) {
    u32 output = 0;

    asm(
        "mov %0, #0xFF\n"
        "and %0, #0xF0\n"
        : "=r" (output)
    );

    expect_eq(output, 0xF0);
}

define_test(test_arm_add) {
    u32 output = 0;

    asm(
        "mov %0, #7\n"
        "add %0, #8\n"
        : "=r" (output)
    );

    expect_eq(output, 15);
}

define_test(test_arm_orr) {
    u32 output = 0;

    asm(
        "mov %0, #0x0F\n"
        "orr %0, #0xF0\n"
        : "=r" (output)
    );

    expect_eq(output, 0xFF);
}

define_test(test_arm_cmp) {
    u32 output = 0;

    asm(
        "mov r1, #7\n"
        "mov r2, #7\n"
        "cmp r1, r2\n"
        "mov %0, #0\n"
        "beq success\n"
        "add %0, #1\n"
        "success:\n"
        "   add %0, #1\n"
        : "=r" (output)
    );

    // result should be 1 since branch should be taken
    expect_eq(output, 1);
}

define_test(test_arm_eor) {
    u32 output = 0;

    asm(
        "mov %0, #0xF0\n"
        "eor %0, #0x0F\n"
        : "=r" (output)
    );

    expect_eq(output, 0xFF);
}

define_test(test_arm_sub) {
    u32 output = 0;

    asm(
        "mov %0, #61\n"
        "sub %0, #45\n"
        : "=r" (output)
    );

    expect_eq(output, 16);
}

define_test(test_arm_rsb) {
    u32 output = 0;

    asm(
        "mov %0, #45\n"
        "rsb %0, #61\n"
        : "=r" (output)
    );

    expect_eq(output, 16);
}

define_test(test_arm_adc) {
    u32 output = 0;

    asm(
        "msr cpsr_f, #0\n"
        "mov %0, #7\n"
        "adc %0, #15\n"
        : "=r" (output)
    );

    expect_eq(output, 22);

    output = 0;

    asm(
        "msr cpsr_f, 0x20000000\n"
        "mov %0, #7\n"
        "adc %0, #15\n"
        : "=r" (output)
    );

    expect_eq(output, 23);
}

define_test(test_arm_sbc) {
    u32 output = 0;

    asm(
        "msr cpsr_f, #0\n"
        "mov %0, #20\n"
        "sbc %0, #17\n"
        : "=r" (output)
    );

    expect_eq(output, 2);

    output = 0;

    asm(
        "msr cpsr_f, 0x20000000\n"
        "mov %0, #20\n"
        "sbc %0, #17\n"
        : "=r" (output)
    );

    expect_eq(output, 3);
}

define_test(test_arm_rsc) {
    u32 output = 0;

    asm(
        "msr cpsr_f, #0\n"
        "mov %0, #17\n"
        "rsc %0, #20\n"
        : "=r" (output)
    );

    expect_eq(output, 2);

    output = 0;

    asm(
        "msr cpsr_f, 0x20000000\n"
        "mov %0, #17\n"
        "rsc %0, #20\n"
        : "=r" (output)
    );

    expect_eq(output, 3);
}

define_test(test_arm_tst) {
    u32 output = 0;

    asm(
        "mov r1, #0xFF0\n"
        "mov r2, #0x00F\n"
        "tst r1, r2\n"
        "mov %0, #0\n"
        "beq success1\n"
        "add %0, #1\n"
        "success1:\n"
        "   add %0, #1\n"
        : "=r" (output)
    );

    // result should be 1 since branch should be taken
    expect_eq(output, 1);
}

define_test(test_arm_teq) {
    u32 output = 0;

    asm(
        "mov r1, #0xF\n"
        "mov r2, #0xF\n"
        "teq r1, r2\n"
        "mov %0, #0\n"
        "beq success2\n"
        "add %0, #1\n"
        "success2:\n"
        "   add %0, #1\n"
        : "=r" (output)
    );

    // result should be 1 since branch should be taken
    expect_eq(output, 1);
}

define_test(test_arm_cmn) {
    u32 output = 0;

    asm(
        "mov r1, #0xFFFFFFFF\n"
        "mov r2, #1\n"
        "cmn r1, r2\n"
        "mov %0, #0\n"
        "beq success3\n"
        "add %0, #1\n"
        "success3:\n"
        "   add %0, #1\n"
        : "=r" (output)
    );

    // result should be 1 since branch should be taken
    expect_eq(output, 1);
}

define_test(test_arm_bic) {
    u32 output = 0;

    asm(
        "mov %0, #0xF\n"
        "bic %0, #0xE\n"
        : "=r" (output)
    );

    expect_eq(output, 0x1);
}

define_test(test_arm_data_processing_r15) {
    // r15 as operand
    u32 output = 0;

    asm(
        "add r1, r15, #4\n"
        "mov r2, r15\n"
        "sub %r0, r1, r2"
        : "=r" (output)
    );

    expect_eq(output, 0x0);
}