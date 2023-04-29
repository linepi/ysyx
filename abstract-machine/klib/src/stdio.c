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
  va_list copy_ap;
  va_copy(copy_ap, ap);
  int len = vsprintf(NULL, fmt, ap);
  char _buf[len+1];
  char *buf = _buf;

  int __len = vsprintf(buf, fmt, copy_ap);
  assert(__len == len);
  while (*buf) putch(*buf++);
  va_end(copy_ap);
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
      fmt++;
      char pre = '\0';
      int nr_pre = 0;
      if (*fmt == '0') {
        pre = '0';
        fmt++;
      }
      else if (*fmt <= '9' && *fmt >= '1') pre = ' ';
      while (*fmt <= '9' && *fmt >= '1') {
        nr_pre *= 10;
        nr_pre += *fmt - '0';
        fmt++;
      }
      char *saved_out = out;

      switch (*fmt) {
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
          else out += INTEGER_LEN(u, 10);
          break;
        case 'x':
          unsigned int x = va_arg(ap, unsigned int);
          if (valid) out += utoa(x, out, 16);
          else out += INTEGER_LEN(x, 16);
          break;
        case 'l':
          switch (*(fmt+2)) {
            case 'd':
              long int ld = va_arg(ap, long int);
              if (valid) out += ltoa(ld, out, 10);
              else out += INTEGER_LEN(ld, 10);
              break;
            case 'u':
              unsigned long lu = va_arg(ap, unsigned long);
              if (valid) out += ultoa(lu, out, 10);
              else out += INTEGER_LEN(lu, 10);
              break;
            case 'x':
              unsigned long lx = va_arg(ap, unsigned long);
              if (valid) out += ultoa(lx, out, 16);
              else out += INTEGER_LEN(lx, 16);
              break;
            case 'f':
            default: panic("Not implemented");
          }
          fmt += 1;
          break;
        case 'f':
        default: panic("Not implemented");
      }
      int added_len = out - saved_out;
      if (nr_pre > added_len) {
        if (valid) {
          // move string forward nr_pre - added_len char
          for (int i = added_len - 1; i >= 0; i--) {
            saved_out[i + nr_pre - added_len] = saved_out[i]; 
          }
          // fill pre
          for (int i = 0; i < nr_pre - added_len; i++) {
            saved_out[i] = pre;
          }
        } 
        out = saved_out + nr_pre;
      }
      fmt += 1;
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
