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

    mov r12, #0

test0:
    mov r0, #32
    cmp r0, #32
    bne finish_tests

    add r12, #1

all_tests_passed:
    mov r12, #-1

finish_tests:
    mov r0, r12
    ldr r12, =old_state
    ldmia r12!, {r1-r11, r13-r14}
    
    bx lr