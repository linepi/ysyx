#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vtop.h>  
#include <nvboard.h>
// #define SEQUENTIAL

Vtop *top;

#ifdef SEQUENTIAL
void single_cycle() {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}
// void reset(int n) {
//   top->rst = 1;
//   while (n-- > 0) single_cycle();
//   top->rst = 0;
// }
#endif
 
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vtop{contextp};
  
  while (!contextp->gotFinish()) {
    
#ifdef SEQUENTIAL
    single_cycle();
#else
    top->eval();
#endif

  }
  top->final();
  delete top;
  delete contextp;
  return 0;
}
