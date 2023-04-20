#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define b(number, n) ({ \
    static char output[64 + 1]; \
    for (int i = n - 1; i >= 0; i--) { \
        output[n - i - 1] = (number & (1 << i)) ? '1' : '0'; \
    } \
    output[n] = '\0'; \
    output; \
}) 

#define MSIZE 0x8000000 
#define PG_ALIGN __attribute__((aligned(4096)))
#define MBASE 0x80000000
typedef uint32_t paddr_t;
typedef uint64_t word_t;
typedef int64_t sword_t;

#endif