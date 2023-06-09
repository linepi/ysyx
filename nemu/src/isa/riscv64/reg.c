/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  printf(ANSI_FMT("Reg info:\n", ANSI_FG_GREEN));
  for(int i = 0; i < 32; i++) {
    printf("%s: ", reg_name(i));
    if (strlen(reg_name(i)) != 3) putchar(' ');
    printf("0x%016lx\n", gpr(i));
  }
}

void clear_reg() {
  for(int i = 0; i < 32; i++) {
    gpr(i) = 0;
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if (strcmp(s, "pc") == 0) {
    return cpu.pc;
  } else if (strcmp(s, "mtvec") == 0) {
    return cpu.mtvec;
  } else if (strcmp(s, "mstatus") == 0) {
    return cpu.mstatus;
  } else if (strcmp(s, "mepc") == 0) {
    return cpu.mepc;
  } else if (strcmp(s, "mcause") == 0) {
    return cpu.mcause;
  }
  for( int i = 0; i < 32; i++) {
    if (strcmp(s, regs[i]) == 0) {
      return gpr(i);
    }
  }
  *success = false;
  return 0;
}
