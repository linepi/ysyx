#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vprintf(fmt, ap);
  va_end(ap);
  return len;
}

int vprintf(const char *fmt, va_list ap) {
  int len = vsprintf(NULL, fmt, ap);
  char _buf[len+1];
  char *buf = _buf;
  assert(_buf != NULL);
  int __len = vsprintf(buf, fmt, ap);
  assert(__len == len);
  while (*buf) putch(*buf++);
  return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  bool valid = (out != NULL); // if out = NULL, do not dereference it
  char *base = out;
  while (*fmt) {
    if (*fmt != '%') {
      if (valid) *out = *fmt;
      out++;
      fmt++;
    } else {
      switch (*(fmt+1)) 
      {
      case 's':
        char *str = va_arg(ap, char *);
        if (valid) strcpy(out, str);
        out += strlen(str);
        break;
      case 'c':
        if (valid) *out = va_arg(ap, int);
        out++;
        break;
      case 'd':
        int d = va_arg(ap, int);
        if (valid) out += itoa(d, out, 10);
        else out += INTEGER_LEN(d, 10);
        break;
      case 'u':
        unsigned int u = va_arg(ap, unsigned int);
        if (valid) out += utoa(u, out, 10);
        else out += INTEGER_LEN(d, 10);
        break;
      case 'x':
        unsigned int x = va_arg(ap, unsigned int);
        if (valid) out += itoa(x, out, 16);
        else out += INTEGER_LEN(d, 16);
        break;
      case 'l':
        switch (*(fmt+2))
        {
        case 'd':
          long int ld = va_arg(ap, long int);
          if (valid) out += ltoa(ld, out, 10);
          else out += INTEGER_LEN(d, 10);
          break;
        case 'u':
          unsigned long lu = va_arg(ap, unsigned long);
          if (valid) out += ultoa(lu, out, 10);
          else out += INTEGER_LEN(d, 10);
          break;
        case 'x':
          unsigned long lx = va_arg(ap, unsigned long);
          if (valid) out += ltoa(lx, out, 16);
          else out += INTEGER_LEN(d, 16);
          break;
        default: panic("Not implemented");
        }
        fmt += 1;
        break;
      default: panic("Not implemented");
      }
      fmt += 2;
    }
  }
  if (valid) *out = '\0';
  return out - base;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}


#endif
