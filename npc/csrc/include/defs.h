#ifndef __DEFS_H__
#define __DEFS_H__

word_t pmem_read(paddr_t paddr, int len);
uint8_t* guest_to_host(paddr_t paddr);
void set_ptr(void *pc, int flag);
extern vaddr_t *pc;
extern uint32_t *inst;


#endif