#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vprintf(const char *fmt, va_list ap) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char *base = out;
  while (*fmt) {
    if (*fmt != '%') {
      *out = *fmt;
      out++;
      fmt++;
    } else {
      switch (*(fmt+1)) {
      case 's':
        char *str = va_arg(ap, char *);
        strcpy(out, str);
        out += strlen(str);
        break;
      case 'c':
        *out++ = va_arg(ap, int);
        break;
      case 'd':
        int i = va_arg(ap, int);
        if (i < 0) *out++ = '-';
        out += itoa(i, out, 10);
        break;
      case 'u':
        unsigned int u = va_arg(ap, unsigned int);
        out += itoa(u, out, 10);
        break;
      case 'x':
        unsigned int x = va_arg(ap, unsigned int);
        out += itoa(x, out, 16);
        break;
      default: panic("Not implemented");
      }
      fmt += 2;
    }
  }
  *out = '\0';
  return strlen(base);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
