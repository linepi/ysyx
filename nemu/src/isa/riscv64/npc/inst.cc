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
#include <VPC.h> 

VPC *PC;
void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}

static int decode_exec(Decode *s) {
  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch_add(&s->snpc, 4);
  // what the hell does this line do?
  // no other than update Registers(cpu variable), write(read) to(from) pmem.
  // so, maybe I can redefine the decode_exec function, so that all other things can work?
  // how?
  // You know, verilator just convert .v files to cpp files, so,
  // If only I can link the cpp files to my nemu and then use it, awesome!
  return decode_exec(s);
}

 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  PC = new VPC{contextp};
  
  int cnt = 0;
  srand((unsigned) time(NULL));
  PC->pc = MBASE;
  while (!contextp->gotFinish()) {
    PC->inst = pmem_read(PC->pc, 4);
    printf(ANSI_FMT("execute %016lx: %08x\n", ANSI_FG_GREEN), PC->pc, PC->inst);
    single_cycle();
    if (PC->ebreak) {
      printf(ANSI_FMT("Program hit ebreak, stop.\n", ANSI_FG_GREEN));
      break;
    }
  }
  PC->final();
  delete PC;
  delete contextp;
  return 0;
}