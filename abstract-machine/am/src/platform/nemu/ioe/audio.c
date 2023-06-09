#include <am.h>
#include <nemu.h>
#include <klib.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

static uint32_t sbufsize;
static uint32_t sbuf_r;

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = inl(AUDIO_INIT_ADDR);
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
  sbufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  // init SDL audio module
  outl(AUDIO_INIT_ADDR, true);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  return;
  uint8_t *start = ctl->buf.start;
  uint8_t *end = ctl->buf.end;
  if (end - start < 0) return;
  uint32_t len = end - start;
  // 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待
  // 直到有足够的空闲空间将音频数据完全写入流缓冲区才会返回.
  while (sbufsize - inl(AUDIO_COUNT_ADDR) < len); 
  while (start <= end) {
    outb(AUDIO_SBUF_ADDR + sbuf_r, *start);
    sbuf_r = (sbuf_r + 1) & (sbufsize - 1);
    start++;
  } 
}
