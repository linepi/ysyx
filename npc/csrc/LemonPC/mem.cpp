#include "common.h"
#include "defs.h"
#include "mem.h"
#include "macro.h"

static uint8_t pmem[MSIZE] PG_ALIGN = {
    0x93, 0x00, 0x30, 0x00,  // addi x1, x0, 3
    0x93, 0x81, 0x40, 0x00,  // addi x3, x1, 4
    0x13, 0x81, 0xe1, 0xff,  // addi x2, x3, -2
    0x13, 0x81, 0x81, 0xc1,  // addi x2, x3, -1000
    0x93, 0x81, 0x81, 0xf3,  // addi x3, x3, -200
    0x13, 0x81, 0xd0, 0x00,  // addi x2, x1, 13
    0x73, 0x00, 0x10, 0x00
};

word_t pmem_read(paddr_t paddr, int len) {
    uint8_t* host = guest_to_host(paddr); 
    switch (len) {
        case 1: return *(uint8_t  *)host;
        case 2: return *(uint16_t *)host;
        case 4: return *(uint32_t *)host;
        case 8: return *(uint64_t *)host;
        default: assert(0);
    }
}

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - MBASE; }