#ifndef __MIPS32_REG_H__
#define __MIPS32_REG_H__

#include "common.h"

#define PC_START 0x100000

typedef struct {
  union {
    rtlreg_t _32;
    uint16_t _16[2];
    uint8_t _8[4];
  } gpr[32];

  uint32_t status;
  rtlreg_t lo, hi;
  uint32_t badvaddr;
  uint32_t cause;
  vaddr_t pc;
  uint32_t epc;

  bool INTR;
} CPU_state;

static inline int check_reg_index(int index) {
  assert(index >= 0 && index < 32);
  return index;
}

#define reg_l(index) (cpu.gpr[check_reg_index(index)]._32)

static inline const char* reg_name(int index, int width) {
  extern const char* regsl[];
  assert(index >= 0 && index < 32);
  return regsl[index];
}

#endif