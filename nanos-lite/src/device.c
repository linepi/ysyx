#include <common.h>
#include "fs.h"

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

int system_w, system_h;

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

size_t serial_write(const void *buf, size_t offset, size_t len) {
  char *str = (char *)buf;
  for (int i = 0; i < len; i++) putch(str[i]);
  return len;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  if (ev.keycode == AM_KEY_NONE) return 0;
  int writed = sprintf((char *)buf, "KEY:%s\nCODE:%d\nACTION:%s\n", keyname[ev.keycode], ev.keycode, ev.keydown ? "DOWN" : "UP");
  assert(writed <= len);
  return writed;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  int writed = sprintf((char *)buf, "WIDTH : %d\n HEIGHT : %d\n", system_w, system_h);
  assert(writed <= len);
  return writed;
}

extern Finfo file_table[];
size_t fb_write(const void *buf, size_t offset, size_t len) {
  assert(len % 4 == 0);
  assert(offset == 0);

  size_t left_size = file_table[FD_FB].size - file_table[FD_FB].seek_offset;
  size_t actual_off = file_table[FD_FB].seek_offset + offset;
  size_t actual_len = len > left_size ? left_size : len;
  if (actual_len != len) Log("warning: fb write overflow");

  for (int i = 0; i < actual_len / 4; i++) {
    int true_off = actual_off / 4 + i;
    int y = true_off / system_w;
    int x = true_off - y * system_w;
    io_write(AM_GPU_FBDRAW, x, y, (uint32_t *)buf + i, 1, 1, false);
  }
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
  file_table[FD_FB].seek_offset += actual_len;
  return 0;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
