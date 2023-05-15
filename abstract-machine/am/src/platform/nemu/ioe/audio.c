#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

static int sbufsize;
static int sbuf_r;

void __am_audio_init() {
  sbufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = inl(AUDIO_INIT_ADDR);
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  uint8_t *start = ctl->buf.start;
  uint8_t *end = ctl->buf.end;
  int len = end - start;
  // 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待
  // 直到有足够的空闲空间将音频数据完全写入流缓冲区才会返回.
  printf("sbufsize = %u, count = %u\n, len = %d", sbufsize, inl(AUDIO_COUNT_ADDR), len);
  while (sbufsize - inl(AUDIO_COUNT_ADDR) < len) {
    printf("%d - %d < %d\n", sbufsize, inl(AUDIO_COUNT_ADDR), len);
  }; 
  while (start <= end) {
    outb(AUDIO_SBUF_ADDR + sbuf_r, *start);
    sbuf_r = (sbuf_r + 1) & (sbufsize - 1);
    start++;
  } 
}
