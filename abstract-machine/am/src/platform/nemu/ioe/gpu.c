#include <am.h>
#include <nemu.h>
#include <klib.h>
#include <omp.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
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
  int w = reg_screensize >> 16;  
  int h = reg_screensize & 0xffff;  
  int p_idx = 0;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
#pragma omp parallel for 
  for (int j = ctl->y; j < ctl->y + ctl->h; j++) {
    for (int i = ctl->x; i < ctl->x + ctl->w; i++) {
      outl(FB_ADDR + 4 * (j*w + i), pixels[p_idx++]);
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
