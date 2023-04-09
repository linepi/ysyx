#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vnb.h>  
#include <nvboard.h>
#define SEQUENTIAL

Vnb *nb;

#ifdef SEQUENTIAL
void single_cycle() {
  nb->clk = 0; 
  nb->eval();
  nb->clk = 1; 
  nb->eval();
}
// void reset(int n) {
//   nb->rst = 1;
//   while (n-- > 0) single_cycle();
//   nb->rst = 0;
// }
#endif
 
void nvboard_bind_all_pins(Vnb* nb);
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  nb = new Vnb{contextp};
  
  nvboard_bind_all_pins(nb);
  nvboard_init();
 
  while (!contextp->gotFinish()) {
    sleep(1); 
#ifdef SEQUENTIAL
    single_cycle();
#else
    nb->eval();
#endif

    nvboard_update();
  }
  nb->final();
  delete nb;
  delete contextp;
  nvboard_quit();
  return 0;
}
