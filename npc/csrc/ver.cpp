#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vver.h>  
#include <time.h>
#include "common.h"
#include "defs.h"
// #define SEQUENTIAL

Vver *ver;

#ifdef SEQUENTIAL
void single_cycle() {
  ver->clk = 0; ver->eval();
  ver->clk = 1; ver->eval();
}
void reset(int n) {
  ver->rst = 1;
  while (n-- > 0) single_cycle();
  ver->rst = 0;
}
#endif
 
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  ver = new Vver{contextp};
  
  int cnt = 0;
  srand((unsigned) time(NULL));
  while (!contextp->gotFinish()) {
    ver->inst = pmem_read(ver->pc, 4);
#ifdef SEQUENTIAL
    single_cycle();
#else
    ver->eval();
#endif

  }
  ver->final();
  delete ver;
  delete contextp;
  return 0;
}
