#include <nds.h>
#include <stdio.h>

extern int run_data_processing_tests();

int main(void) {
    consoleDemoInit();

    int test_failed = run_data_processing_tests();

    if (test_failed != -1) {
        printf("data processing\nfailed test %d\n", test_failed);
    } else {
        printf("data processing\nall tests passed!\n");
    }

    while(1) {}
}