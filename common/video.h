#pragma once

#include <stdint.h>

void save_vramcnt();
void restore_vramcnt();

void write_vramcnt_a(uint8_t data);
void write_vramcnt_b(uint8_t data);
void write_vramcnt_c(uint8_t data);
void write_vramcnt_d(uint8_t data);
void write_vramcnt_e(uint8_t data);
void write_vramcnt_f(uint8_t data);
void write_vramcnt_g(uint8_t data);
void write_vramcnt_h(uint8_t data);
void write_vramcnt_i(uint8_t data);