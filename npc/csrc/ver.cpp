#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vver.h>  
#include <time.h>
#include "svdpi.h"
#include "verilated_dpi.h"
#include "Vver__Dpi.h"
#include <Vver.h> 

#include <common.h>
#include <defs.h>
#include <macro.h>
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

extern "C" void set_ptr(void *ptr, int flag) {
	switch (flag) {
		case 0: pc = (vaddr_t *)ptr; break;
		case 1: inst = (uint32_t *)ptr; break;
		default: assert(0);
	}	
} 
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  ver = new Vver{contextp};
  
  int cnt = 0;
  srand((unsigned) time(NULL));

  while (!contextp->gotFinish()) {
    ver->a = rand() & 1;
    ver->b = rand() & 1;
    MUXDEF(SEQUENTIAL, single_cycle(), ver->eval());
    // printf("%s & %s = %s\n", b(ver->a,1), b(ver->b,1), b(ver->c, 1));
  }
  ver->final();
  delete ver;
  delete contextp;
  return 0;
}
