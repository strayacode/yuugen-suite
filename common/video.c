#include "video.h"
#include "types.h"
#include "defines.h"

static u8 vramcnt[9];

void save_vramcnt() {
    vramcnt[0] = VRAMCNT_A;
    vramcnt[1] = VRAMCNT_B;
    vramcnt[2] = VRAMCNT_C;
    vramcnt[3] = VRAMCNT_D;
    vramcnt[4] = VRAMCNT_E;
    vramcnt[5] = VRAMCNT_F;
    vramcnt[6] = VRAMCNT_G;
    vramcnt[7] = VRAMCNT_H;
    vramcnt[8] = VRAMCNT_I;
}

void restore_vramcnt() {
    VRAMCNT_A = vramcnt[0];
    VRAMCNT_B = vramcnt[1];
    VRAMCNT_C = vramcnt[2];
    VRAMCNT_D = vramcnt[3];
    VRAMCNT_E = vramcnt[4];
    VRAMCNT_F = vramcnt[5];
    VRAMCNT_G = vramcnt[6];
    VRAMCNT_H = vramcnt[7];
    VRAMCNT_I = vramcnt[8];
}

void write_vramcnt_a(u8 data) {
    vramcnt[0] = VRAMCNT_A;
    VRAMCNT_A = data;
}

void write_vramcnt_b(u8 data) {
    vramcnt[1] = VRAMCNT_B;
    VRAMCNT_B = data;
}

void write_vramcnt_c(u8 data) {
    vramcnt[2] = VRAMCNT_C;
    VRAMCNT_C = data;
}

void write_vramcnt_d(u8 data) {
    vramcnt[3] = VRAMCNT_D;
    VRAMCNT_D = data;
}

void write_vramcnt_e(u8 data) {
    vramcnt[4] = VRAMCNT_E;
    VRAMCNT_E = data;
}

void write_vramcnt_f(u8 data) {
    vramcnt[5] = VRAMCNT_F;
    VRAMCNT_F = data;
}

void write_vramcnt_g(u8 data) {
    vramcnt[6] = VRAMCNT_G;
    VRAMCNT_G = data;
}

void write_vramcnt_h(u8 data) {
    vramcnt[7] = VRAMCNT_H;
    VRAMCNT_H = data;
}

void write_vramcnt_i(u8 data) {
    vramcnt[8] = VRAMCNT_I;
    VRAMCNT_I = data;
}
