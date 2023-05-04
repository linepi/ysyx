#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  int tmp = inl(KBD_ADDR);
  kbd->keydown = (tmp & KEYDOWN_MASK) != 0;
  kbd->keycode = tmp & 0x7fff;
}
