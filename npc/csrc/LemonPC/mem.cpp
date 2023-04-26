#include "common.h"
#include "defs.h"

static uint8_t pmem[MSIZE] PG_ALIGN = {};

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