.arm
.text
.global run_data_processing_tests

old_state:
    .space 0x40

@ register allocation:
@ r0-r5: for basic arithmetic
@ r12: test number and for saving and restoring state

run_data_processing_tests:
    @ store the current state
    ldr r12, =old_state
    stmia r12!, {r1-r11, r13-r14}

    @ test 0: mov
    mov r12, #0
    mov r0, #32
    cmp r0, #32
    bne finish_tests

    @ test 1: cmp
    mov r12, #1
    mov r0, #32
    mov r1, #32
    cmp r0, r1
    bne finish_tests

    @ test 2: and
    mov r12, #2
    mov r0, #0xFF0
    and r0, #0x0F0
    cmp r0, #0x0F0
    bne finish_tests

    @ test 3: eor
    mov r12, #3
    mov r0, #0xF0
    eor r0, #0x0F
    cmp r0, #0xFF
    bne finish_tests

    @ test 4: sub
    mov r12, #4
    mov r0, #61
    sub r0, #45
    cmp r0, #16
    bne finish_tests

    @ test 5: rsb
    mov r12, #5
    mov r0, #45
    rsb r0, #61
    cmp r0, #16
    bne finish_tests

    @ test 6: add
    mov r12, #6
    mov r0, #7
    add r0, #8
    cmp r0, #15
    bne finish_tests

    @ test 7: adc with carry bit 0
    mov r12, #7
    msr cpsr_f, #0
    mov r0, #7
    adc r0, #15
    cmp r0, #22
    bne finish_tests

    @ test 8: adc with carry bit 1
    mov r12, #8
    msr cpsr_f, #0x20000000
    mov r0, #7
    adc r0, #15
    cmp r0, #23
    bne finish_tests

    @ test 9: sbc with carry bit 0
    mov r12, #9
    msr cpsr_f, #0
    mov r0, #20
    sbc r0, #17
    cmp r0, #2
    bne finish_tests

    @ test 10: sbc with carry bit 1
    mov r12, #10
    msr cpsr_f, #0x20000000
    mov r0, #20
    sbc r0, #17
    cmp r0, #3
    bne finish_tests

    @ test 11: rsc with carry bit 0
    mov r12, #11
    msr cpsr_f, #0
    mov r0, #17
    rsc r0, #20
    cmp r0, #2
    bne finish_tests

    @ test 12: rsc with carry bit 1
    mov r12, #12
    msr cpsr_f, #0x20000000
    mov r0, #17
    rsc r0, #20
    cmp r0, #3
    bne finish_tests

    @ test 13: tst
    mov r12, #13
    mov r0, #0xFF0
    tst r0, #0x00F
    bne finish_tests
    
    @ test 14: teq
    mov r12, #14
    mov r0, #0xF0
    tst r0, #0x0F
    bne finish_tests

    @ test 15: cmn
    mov r12, #15
    mov r0, #32
    mov r1, #-32
    cmn r0, r1
    bne finish_tests

    @ test 16: orr
    mov r12, #16
    mov r0, #0xF0
    orr r0, #0x0F
    cmp r0, #0xFF
    bne finish_tests

    @ test 17: bic
    mov r12, #17
    mov r0, #0xF
    bic r0, #0xE
    cmp r0, #1
    bne finish_tests

    @ test 18: mvn
    mov r12, #18
    mvn r0, #0xFFFFFFF0
    cmp r0, #0xF
    bne finish_tests

all_tests_passed:
    mov r12, #-1

finish_tests:
    mov r0, r12
    ldr r12, =old_state
    ldmia r12!, {r1-r11, r13-r14}
    
    bx lr