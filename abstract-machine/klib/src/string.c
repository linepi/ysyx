#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  const char *start = s;
  while (*s++);
  return s - start - 1;
}

char *strcpy(char *dst, const char *src) {
  char *save = dst;
	for (; (*dst = *src); ++dst, ++src);
	return save;
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

int strcmp(const char *s1, const char *s2)
{
  while (*s1){
    if (*s1 != *s2) break;
    s1++; s2++;
  }
  return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (*s1 && n--){
    if (*s1 != *s2) break;
    s1++; s2++;
  }
  return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *ptr = (unsigned char*)s;
  while (n--) {
    *ptr++ = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  return memcpy(dst, src, n);
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
  for (; n--; s1++, s2++) {
    unsigned char u1 = * (unsigned char *) s1;
    unsigned char u2 = * (unsigned char *) s2;
    if (u1 != u2) return u1 - u2;
  }
  return 0;
}

void
strrev(char *str)
{
	int i;
	int j;
	unsigned char a;
	unsigned len = strlen((const char *)str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}

#endif
