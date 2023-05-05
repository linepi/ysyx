#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <VPC.h>  
#include <time.h>

#include <common.h>
#include <defs.h>
#include <macro.h>
#include <mem.h>

VPC *PC;
void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
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
    if (PC->inst == 0) break;
    printf("%016lx: %08x\n", PC->pc, PC->inst);
    printf("%d, %d\n", PC->rs1, PC->rs2);
    single_cycle();
  }
  PC->final();
  delete PC;
  delete contextp;
  return 0;
}
