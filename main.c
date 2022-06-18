#include <nds.h>
#include <stdio.h>
#include "cpu/arm.h"

#define NUM_CPU_TESTS 19

int main(void) {
    PrintConsole* console = consoleDemoInit();
    consoleSetWindow(console, 2, 2, 256, 192);

    test_arm_data_processing();
    
    while(1) {}
}