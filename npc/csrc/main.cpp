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
void reset(int n) {
  top->rst = 1;
  while (n-- > 0) single_cycle();
  top->rst = 0;
}
#endif
 
void nvboard_bind_all_pins(Vtop* top);
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vtop{contextp};
  
  nvboard_bind_all_pins(top);
  nvboard_init();
 
  while (!contextp->gotFinish()) {
#ifdef SEQUENTIAL
    single_cycle();
#else
    top->eval();
#endif
    nvboard_update();
  }
  delete top;
  delete contextp;
  nvboard_quit();
  return 0;
}