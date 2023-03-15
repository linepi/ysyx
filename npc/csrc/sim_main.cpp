#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Vour.h"  // create `top.v`,so use `Vtop.h`
#include "verilated.h"
 
#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
 
int main(int argc, char** argv, char** env) {
 
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vour* our = new Vour{contextp};
  
 
  // wave part
  // VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
  // contextp->traceEverOn(true); //打开追踪功能
  // our->trace(tfp, 0); //
  // tfp->open("wave.vcd"); //设置输出的文件wave.vcd
 
 
  while (!contextp->gotFinish()) {
    int a = rand() & 1;
    int b = rand() & 1;
    our->a = a;
    our->b = b;
    our->eval();
    printf("a = %d, b = %d, f = %d\n", a, b, our->f);
 
    // wave part
    tfp->dump(contextp->time()); //dump wave
    contextp->timeInc(1); //推动仿真时间
 
    assert(our->f == a ^ b);
  }

  delete our;
  // tfp->close();
  delete contextp;
  return 0;
}
