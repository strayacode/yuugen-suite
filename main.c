#include <nds.h>
#include <stdio.h>
#include "cpu/arm.h"

int main(void) {
    PrintConsole* console = consoleDemoInit();
    consoleSetWindow(console, 2, 2, 256, 192);

    printf("yuugen-suite\n");

    run_test(test_arm_mov);
    run_test(test_arm_add);

    int ran = get_tests_ran();
    int failed = get_tests_failed();
    float success_rate = (((float)ran - (float)failed) / (float)ran) * 100.0f;

    printf("Tests: %d, Failed: %d\n", ran, failed);
    printf("Success rate: %.2f%%\n", success_rate);
    
    while(1) {}
}