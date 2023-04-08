#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Vver.h>  
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
  
  while (!contextp->gotFinish()) {
    ver->a = rand() & 1;
    ver->b = rand() & 1; 
#ifdef SEQUENTIAL
    single_cycle();
#else
    ver->eval();
#endif
    printf("a = %d, b = %d, c = %d\n", ver->a, ver->b, ver->c);
  }
  ver->final();
  delete ver;
  delete contextp;
  return 0;
}
