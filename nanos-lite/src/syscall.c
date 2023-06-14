#include <common.h>
#include "syscall.h"

static const bool strace_open = true;

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

static void strace(uintptr_t *a) {
  printf("%s(%lx, %lx, %lx)\n", syscall_name[a[0]], a[1], a[2], a[3]);
}

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1; // a7
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  switch (a[0]) {
    case SYS_yield: {
      if (strace_open) strace(a);
      yield(); 
      c->GPRx = 0;
      break;
    }
    case SYS_exit: {
      if (strace_open) strace(a);
      halt(a[1]);
      break;
    }
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
