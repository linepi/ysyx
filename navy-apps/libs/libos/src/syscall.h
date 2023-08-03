#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#define SYSDEF(name, func) name, 
enum {
#include "syscall.def"
};
#undef SYSDEF

#endif
