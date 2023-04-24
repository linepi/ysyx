#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while (*s++) len++;
  return len;
}

char *strcpy(char *dst, const char *src) {
  while (*src) {
    *dst = *src;
    src++;
    dst++;
  }
  *dst = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++)
      dst[i] = src[i];
  for ( ; i < n; i++)
      dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  strcpy(dst + strlen(dst), src);
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2 && *s1 == *s2) {
    s1++; s2++;
  }  
  if (*s1) {
    if (*s2) return *s1 > *s2;
    else return 1;
  }
  if (*s2) {
    if (*s1) return *s2 > *s1;
    else return -1;
  }
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (*s1 && *s2 && *s1 == *s2 && n--) {
    s1++; s2++;
  }  
  if (*s1) {
    if (*s2) return *s1 > *s2;
    else return 1;
  }
  if (*s2) {
    if (*s1) return *s2 > *s1;
    else return -1;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  while (n--) {
    *(char *)s = c;
    (char *)s++;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  while (n--) {
    *(char *)dst = *(char *)src;
    (char *)dst++;
    (char *)src++;
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  while (n--) {
    *(char *)out = *(char *)in;
    (char *)out++;
    (char *)in++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (*(char *)s1 != *(char *)s2) return *(char *)s1 > *(char *)s2;
  }
  return 0;
}

#endif
