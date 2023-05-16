#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

int itoa(int num, char *str, int base) {
  if (base != 10 && base != 16) return -1;
  int digit;
  int i = 0;
  int off = 0;
  if (num < 0 && base != 16) {
    str[i++] = '-';
    off = 1;
  }
  for (; num || i == 0; num /= base, i++) {
    digit = num % base;
    if (digit < 0) digit = -digit;
		if (digit < 0xA)
			str[i] = '0' + digit;
		else
			str[i] = 'A' + digit - 0xA;
  }
  str[i] = '\0';
  strrev(str + off);
  return i;
}

int utoa(unsigned int num, char *str, int base) {
  if (base != 10 && base != 16) return -1;
  int digit;
  int i;
  for (i = 0; num || i == 0; num /= base, i++) {
    printf("%d ", num);
    digit = num % base;
		if (digit < 0xA)
			str[i] = '0' + digit;
		else
			str[i] = 'A' + digit - 0xA;
  }
  str[i] = '\0';
  strrev(str);
  return i;
}

int ltoa(long num, char *str, int base) {
  if (base != 10 && base != 16) return -1;
  int digit;
  int i = 0;
  int off = 0;
  if (num < 0 && base != 16) {
    str[i++] = '-';
    off = 1;
  }
  for (; num || i == 0; num /= base, i++) {
    digit = num % base;
    if (digit < 0) digit = -digit;
		if (digit < 0xA)
			str[i] = '0' + digit;
		else
			str[i] = 'A' + digit - 0xA;
  }
  str[i] = '\0';
  strrev(str + off);
  return i;
}

int ultoa(unsigned long num, char *str, int base) {
  if (base != 10 && base != 16) return -1;
  int digit;
  int i;
  for (i = 0; num || i == 0; num /= base, i++) {
    digit = num % base;
		if (digit < 0xA)
			str[i] = '0' + digit;
		else
			str[i] = 'A' + digit - 0xA;
  }
  str[i] = '\0';
  strrev(str);
  return i;
}

void *last_addr = NULL;

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
// #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
//   panic("Not implemented");
// #endif
  if (size == 0) return NULL;
  // ret addr must 8-byte aligned
  size  = (size_t)ROUNDUP(size, 8);

  if (last_addr == NULL) last_addr = heap.start;
  void *ret = last_addr;
  last_addr += size;
  return ret;
}

void free(void *ptr) {
}

#endif
