#include <nds.h>
#include <stdio.h>
#include "cpu/arm.h"
#include "memory/vram_banking.h"

int main(void) {
    PrintConsole* console = consoleDemoInit();
    consoleSetWindow(console, 2, 2, 256, 192);
    save_vramcnt();

    printf("yuugen-suite\n");

    // cpu tests
    run_test(test_arm_mov);
    run_test(test_arm_mvn);
    run_test(test_arm_and);
    run_test(test_arm_add);
    run_test(test_arm_orr);
    run_test(test_arm_cmp);
    run_test(test_arm_eor);
    run_test(test_arm_sub);
    run_test(test_arm_rsb);
    run_test(test_arm_adc);
    run_test(test_arm_sbc);
    run_test(test_arm_rsc);
    run_test(test_arm_tst);
    run_test(test_arm_teq);
    run_test(test_arm_cmn);
    run_test(test_arm_bic);
    run_test(test_arm_data_processing_r15);

    // vram mapping tests
    run_test(test_vram_lcdc);
    run_test(test_vram_overlapping);

    int ran = get_tests_ran();
    int failed = get_tests_failed();
    float success_rate = (((float)ran - (float)failed) / (float)ran) * 100.0f;

    printf("Tests: %d, Failed: %d\n", ran, failed);
    printf("Success rate: %.2f%%\n", success_rate);
    
    while(1) {}
}