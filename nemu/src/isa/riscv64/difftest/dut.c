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
#include <cpu/difftest.h>
#include <utils.h>
#include "../local-include/reg.h"

extern const char *regs[];

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool res = true;
  for (int i = 0; i < 32; i++) {
    uint64_t a1 = ref_r->gpr[i];
    uint64_t a2 = cpu.gpr[i];
    if (a1 != a2) {
      res = false;
      printf(ANSI_FMT("unsame %s", ANSI_FG_RED)", ref: 0x%016lx, cpu: 0x%016lx\n", regs[i], a1, a2);
    }
  }
  if (ref_r->pc != pc) {
    res = false;
    printf(ANSI_FMT("unsame pc", ANSI_FG_RED)", ref: 0x%016lx, cpu: 0x%016lx\n", ref_r->pc, pc);
  }
  return res;
}

void isa_difftest_attach() {

}
