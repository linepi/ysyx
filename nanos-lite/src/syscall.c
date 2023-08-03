#include <common.h>
#include "syscall.h"
#include "fs.h"
#include <sys/types.h>

static const bool strace_open = true;
static const int strace_set[] = {
  SYS_lseek, SYS_open, SYS_read, SYS_close, SYS_gettimeofday
};

extern Finfo file_table[];
int get_nr_file();

uintptr_t sys_exit(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  halt(0);
  Log("Should not reach here");
  return 0;
}

uintptr_t sys_yield(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  return 0;
}

uintptr_t sys_brk(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  return 0; // currently always return zero
}

uintptr_t sys_open(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  return fs_open((const char *)a0, a1, a2);
}

uintptr_t sys_read(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a0 >= 0 && a0 < get_nr_file());
  return fs_read(a0, (void *)a1, a2);
}

uintptr_t sys_write(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a0 >= 0 && a0 < get_nr_file());
  if (file_table[a0].write == NULL) {
    return fs_write(a0, (void *)a1, a2);
  } else {
    return file_table[a0].write((void *)a1, 0, a2);
  }
}

uintptr_t sys_close(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a0 >= 0 && a0 < get_nr_file());
  return fs_close(a0);
}

uintptr_t sys_lseek(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a0 >= 0 && a0 < get_nr_file());
  return fs_lseek(a0, a1, a2);
}

uintptr_t sys_gettimeofday(uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  assert(a1 == 0);
  struct timeval *tp = (struct timeval *)a0;
  uint64_t usecond = io_read(AM_TIMER_UPTIME).us;
  tp->tv_sec = usecond / 1000000;
  tp->tv_usec = usecond % 1000000;
  return 0;
}

#define SYSDEF(name, func) [name] #name,
static char *syscall_name[] = {
#include "syscall.def"
};
#undef SYSDEF

#define SYSDEF(name, func) [name] func,
static uintptr_t (*syscalls[])(uintptr_t, uintptr_t, uintptr_t) = {
#include "syscall.def"
};
#undef SYSDEF

static void strace(uintptr_t a7, uintptr_t a0, uintptr_t a1, uintptr_t a2) {
  bool in = false;
  for (int i = 0; i < sizeof(strace_set)/sizeof(strace_set[0]); i++) {
    if (a7 == strace_set[i]) in = true;
  }
  char *get_fd_filename(int fd);
  if (in) {
    switch (a7) {
    case SYS_lseek: case SYS_read: case SYS_close: case SYS_write:
      printf(ANSI_FMT("[strace]: %s(\"%s\", 0x%lx, 0x%lx)\n", ANSI_FG_BLUE), syscall_name[a7], get_fd_filename(a0), a1, a2);
      break;
    default:
      printf(ANSI_FMT("[strace]: %s(0x%lx, 0x%lx, 0x%lx)\n", ANSI_FG_BLUE), syscall_name[a7], a0, a1, a2);
    }
  }
}

void do_syscall(Context *c) {
  // c->GPR1;  a7
  // c->GPR2;  a0
  // c->GPR3;  a1
  // c->GPR4;  a2
  // c->GPRx;  a0
  if (c->GPR1 < sizeof(syscalls)/sizeof(syscalls[0]) && syscalls[c->GPR1]) {
    if (strace_open) strace(c->GPR1, c->GPR2, c->GPR3, c->GPR4);
    c->GPRx = syscalls[c->GPR1](c->GPR2, c->GPR3, c->GPR4);
  } else {
    panic("Unhandled syscall ID = %d", c->GPR1);
  }
}
