#ifndef __DEFS_H__
#define __DEFS_H__

// mem.cpp
word_t pmem_read(paddr_t paddr, int len);
uint8_t* guest_to_host(paddr_t paddr);
void getpc(void *pc);

#endif