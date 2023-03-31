#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include <Vtop.h>  
#include <nvboard.h>

 
void nvboard_bind_all_pins(Vtop* top);
 
int main(int argc, char** argv, char** env) {
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vtop* top = new Vtop{contextp};
  
  nvboard_bind_all_pins(top);
  nvboard_init();
 
  while (!contextp->gotFinish()) {
    top->eval();
    nvboard_update();
  }
  delete top;
  delete contextp;
  nvboard_quit();
  return 0;
}
