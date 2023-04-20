#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <VPC.h>  
#include <time.h>
#include "common.h"
#include "defs.h"
#define SEQUENTIAL

VPC *PC;

#ifdef SEQUENTIAL
void single_cycle() {
  PC->clk = 0; PC->eval();
  PC->clk = 1; PC->eval();
}
// void reset(int n) {
//   PC->rst = 1;
//   while (n-- > 0) single_cycle();
//   PC->rst = 0;
// }
#endif
 
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  PC = new VPC{contextp};
  
  int cnt = 0;
  srand((unsigned) time(NULL));
  while (!contextp->gotFinish()) {
    printf("%016lx\n", PC->pc);
    PC->inst = pmem_read(PC->pc, 4);
#ifdef SEQUENTIAL
    single_cycle();
#else
    PC->eval();
#endif
    if (cnt++ > 10) break;
  }
  PC->final();
  delete PC;
  delete contextp;
  return 0;
}
