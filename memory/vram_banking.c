#include "../common/testing.h"
#include "../common/types.h"
#include "../common/defines.h"
#include "vram_banking.h"

// TODO: test unaligned vram writes
// TODO: test overlapping banks

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

    *(vu32*)0x06800000 = 0x1;
    *(vu32*)0x0681FFFC = 0x2;
    *(vu32*)0x06820000 = 0x3;
    *(vu32*)0x0683FFFC = 0x4;
    *(vu32*)0x06840000 = 0x5;
    *(vu32*)0x0685FFFC = 0x6;
    *(vu32*)0x06860000 = 0x7;
    *(vu32*)0x0687FFFC = 0x8;
    *(vu32*)0x06880000 = 0x9;
    *(vu32*)0x0688FFFC = 0xA;
    *(vu32*)0x06890000 = 0xB;
    *(vu32*)0x06893FFC = 0xC;
    *(vu32*)0x06894000 = 0xD;
    *(vu32*)0x06897FFC = 0xE;
    *(vu32*)0x06898000 = 0xF;
    *(vu32*)0x0689FFFC = 0x10;
    *(vu32*)0x068A0000 = 0x11;
    *(vu32*)0x068A3FFC = 0x12;

    u32 bank_a_start = *(vu32*)0x06800000;
    u32 bank_a_end = *(vu32*)0x0681FFFC;
    u32 bank_b_start = *(vu32*)0x06820000;
    u32 bank_b_end = *(vu32*)0x0683FFFC;
    u32 bank_c_start = *(vu32*)0x06840000;
    u32 bank_c_end = *(vu32*)0x0685FFFC;
    u32 bank_d_start = *(vu32*)0x06860000;
    u32 bank_d_end = *(vu32*)0x0687FFFC;
    u32 bank_e_start = *(vu32*)0x06880000;
    u32 bank_e_end = *(vu32*)0x0688FFFC;
    u32 bank_f_start = *(vu32*)0x06890000;
    u32 bank_f_end = *(vu32*)0x06893FFC;
    u32 bank_g_start = *(vu32*)0x06894000;
    u32 bank_g_end = *(vu32*)0x06897FFC;
    u32 bank_h_start = *(vu32*)0x06898000;
    u32 bank_h_end = *(vu32*)0x0689FFFC;
    u32 bank_i_start = *(vu32*)0x068A0000;
    u32 bank_i_end = *(vu32*)0x068A3FFC;

    expect_eq(bank_a_start, 0x1);
    expect_eq(bank_a_end, 0x2);
    expect_eq(bank_b_start, 0x3);
    expect_eq(bank_b_end, 0x4);
    expect_eq(bank_c_start, 0x5);
    expect_eq(bank_c_end, 0x6);
    expect_eq(bank_d_start, 0x7);
    expect_eq(bank_d_end, 0x8);
    expect_eq(bank_e_start, 0x9);
    expect_eq(bank_e_end, 0xA);
    expect_eq(bank_f_start, 0xB);
    expect_eq(bank_f_end, 0xC);
    expect_eq(bank_g_start, 0xD);
    expect_eq(bank_g_end, 0xE);
    expect_eq(bank_h_start, 0xF);
    expect_eq(bank_h_end, 0x10);
    expect_eq(bank_i_start, 0x11);
    expect_eq(bank_i_end, 0x12);
}
