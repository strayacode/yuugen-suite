#include "../common/testing.h"
#include "../common/types.h"
#include "../common/defines.h"
#include "vram_banking.h"

define_test(test_vram_lcdc) {
    write_vramcnt_a(0x80);
    write_vramcnt_b(0x80);
    write_vramcnt_c(0x80);
    write_vramcnt_d(0x80);
    write_vramcnt_e(0x80);
    write_vramcnt_f(0x80);
    write_vramcnt_g(0x80);
    write_vramcnt_h(0x80);
    write_vramcnt_i(0x80);

    *(vu32*)0x06800000 = 0x11;
    *(vu32*)0x0681FFFC = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;
    // *0x0681FFFF = 0x22;

    u32 bank_a_start = *(vu32*)0x06800000;
    u32 bank_a_end = *(vu32*)0x0681FFFC;

    expect_eq(bank_a_start, 0x11);
    expect_eq(bank_a_end, 0x22);
}
