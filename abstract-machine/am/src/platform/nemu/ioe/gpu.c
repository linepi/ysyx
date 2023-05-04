#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // uint32_t reg_screensize = inl(VGACTL_ADDR);
  // int i;
  // int w = reg_screensize >> 16;  
  // int h = reg_screensize & 0xffff;  
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t reg_screensize = inl(VGACTL_ADDR);
  uint32_t width = reg_screensize >> 16;
  uint32_t height = reg_screensize & 0xffff;
  uint32_t size = width * height * sizeof(uint32_t);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = size
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
  uint32_t reg_screensize = inl(VGACTL_ADDR);
  int h = reg_screensize & 0xffff;  
  int p_idx = 0;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  for (int j = ctl->x; j < ctl->x + ctl->w; j ++) {
    for (int i = ctl->y; i < ctl->y + ctl->h; i ++) {
      outl(FB_ADDR + i*h + j, pixels[p_idx++]);
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
