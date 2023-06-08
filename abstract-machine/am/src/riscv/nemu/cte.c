#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

// 此函数接收Context上下文信息，并根据客户程序提供的函数user_handler对这些信息进行处理
Context* __am_irq_handle(Context *c) {
  printf("__am_irq_handle receive this Context:\n");
  // for (int i = 0; i < 32; i++) {
  //   printf("x%d: %lx\n", i, c->gpr[i]);
  // }
  printf("mcause: 0x%lx\n", c->mcause);
  printf("mstatus: 0x%lx\n", c->mstatus);
  printf("mepc: 0x%lx\n", c->mepc);

  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case EVENT_YIELD: ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

// 这个函数先把当前寄存器（包括系统寄存器）的值入栈，然后当作参数传递
// （就是上层看到的Context *c)，调用__am_irq_handle，函数返回，
// 然后将Context的值重新存入寄存器中
extern void __am_asm_trap(void);

// 设置异常入口地址为__am_asm_trap函数地址，并提供一个客户程序定义的handler
bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
  // let yield make mcause equals 1
  asm volatile("csrwi mcause, 1");
  asm volatile("li a7, -1; ecall");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
