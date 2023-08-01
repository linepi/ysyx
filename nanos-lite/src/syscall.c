#include <common.h>
#include "syscall.h"

static const bool strace_open = true;

uintptr_t sys_exit(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  halt(0);
  Log("Should not reach here");
  return 0;
}

uintptr_t sys_yield(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  return 0;
}

uintptr_t sys_write(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a0 == 1 || a0 == 2);
  char *str = (char *)a1;
  for (int i = 0; i < a2; i++) {
    putch(str[i]);
  }
  return a2;
}

uintptr_t sys_brk(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  return 0; // currently always return zero
}

static char *syscall_name[] = {
  [SYS_exit]             "SYS_exit",
  [SYS_yield]            "SYS_yield",        
  [SYS_open]             "SYS_open",        
  [SYS_read]             "SYS_read",        
  [SYS_write]            "SYS_write",        
  [SYS_kill]             "SYS_kill",        
  [SYS_getpid]           "SYS_getpid",        
  [SYS_close]            "SYS_close",        
  [SYS_lseek]            "SYS_lseek",        
  [SYS_brk]              "SYS_brk",
  [SYS_fstat]            "SYS_fstat",        
  [SYS_time]             "SYS_time",        
  [SYS_signal]           "SYS_signal",        
  [SYS_execve]           "SYS_execve",        
  [SYS_fork]             "SYS_fork",        
  [SYS_link]             "SYS_link",        
  [SYS_unlink]           "SYS_unlink",        
  [SYS_wait]             "SYS_wait",        
  [SYS_times]            "SYS_times",        
  [SYS_gettimeofday]     "SYS_gettimeofday"         
};

static uintptr_t (*syscalls[])(uintptr_t, uintptr_t, uintptr_t) = {
  [SYS_exit]            sys_exit, 
  [SYS_yield]           sys_yield,   
  [SYS_open]            NULL, 
  [SYS_read]            NULL,  
  [SYS_write]           sys_write,   
  [SYS_kill]            NULL,  
  [SYS_getpid]          NULL,    
  [SYS_close]           NULL,   
  [SYS_lseek]           NULL,   
  [SYS_brk]             sys_brk, 
  [SYS_fstat]           NULL,   
  [SYS_time]            NULL,  
  [SYS_signal]          NULL,    
  [SYS_execve]          NULL,    
  [SYS_fork]            NULL,  
  [SYS_link]            NULL,  
  [SYS_unlink]          NULL,    
  [SYS_wait]            NULL,  
  [SYS_times]           NULL,   
  [SYS_gettimeofday]    NULL,          
};

static void strace(uintptr_t a7, uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  printf(ANSI_FMT("[strace]: %s(%lx, %lx, %lx)\n", ANSI_FG_BLUE), syscall_name[a7], a0, a1, a2);
}

void do_syscall(Context *c) {
  // c->GPR1;  a7
  // c->GPR2;  a0
  // c->GPR3;  a1
  // c->GPR4;  a2
  // c->GPRx;  a0
  if (c->GPR1 < sizeof(syscalls)/sizeof(syscalls[0]) && syscalls[c->GPR1]) {
    c->GPRx = syscalls[c->GPR1](c->GPR2, c->GPR3, c->GPR4);
    if (strace_open) strace(c->GPR1, c->GPR2, c->GPR3, c->GPR4);
  } else {
    panic("Unhandled syscall ID = %d", c->GPR1);
  }
}
