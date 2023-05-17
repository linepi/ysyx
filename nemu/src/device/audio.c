/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>
#include <macro.h>
#include <pthread.h>

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  nr_reg
};

#define FREQ_OFFSET 0
#define CHANNELS_OFFSET 4
#define SAMPLES_OFFSET 8
#define SBUF_SIZE_OFFSET 12
#define INIT_OFFSET 16
#define COUNT_OFFSET 20
#define OFFSET_DIV 4

static void audio_sbuf_io_handler(uint32_t offset, int len, bool is_write);
static void init_SDL_AudioSpec();
static void audioCallback(void* userdata, Uint8* stream, int len);

static uint8_t *sbuf = NULL;
static uint32_t sbuf_l, sbuf_r, sbuf_count;
static uint32_t *audio_base = NULL;
static SDL_AudioSpec s = {};
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#define R_SBUF ({ \
  uint8_t res; \
  if (sbuf_count > 0) { \
    res = sbuf[sbuf_l]; \
    sbuf_l = (sbuf_l + 1) & (CONFIG_SB_SIZE - 1); \
    sbuf_count--; \
  } else { \
    res = 0; \
  } \
  res; \
})

uint8_t read_sbuf() {
	uint8_t res; 
	if (sbuf_count > 0) { 
		res = sbuf[sbuf_l]; 
		sbuf_l = (sbuf_l + 1) & (CONFIG_SB_SIZE - 1); 
		sbuf_count--; 
	} else { 
		res = 0; 
	} 
	return res; 
}

#define W_SBUF(byte) do { \
  if (sbuf_count <= CONFIG_SB_SIZE) { \
    sbuf[sbuf_r] = byte; \
    sbuf_r = (sbuf_r + 1) & (CONFIG_SB_SIZE - 1); \
    sbuf_count++; \
  } \
} while(0)

static void init_SDL_AudioSpec() {
  s.format = AUDIO_S16SYS;  // 假设系统中音频数据的格式总是使用16位有符号数来表示
  s.userdata = NULL;        // 不使用
  s.callback = audioCallback;
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  switch (offset) {
    case FREQ_OFFSET:
      assert(is_write == 1);
      printf("device register -- freq writed with %d\n", audio_base[FREQ_OFFSET / OFFSET_DIV]);
      s.freq = audio_base[FREQ_OFFSET / OFFSET_DIV];
      break;
    case CHANNELS_OFFSET:
      assert(is_write == 1);
      printf("device register -- channels writed with %d\n", audio_base[CHANNELS_OFFSET / OFFSET_DIV]);
      s.channels = audio_base[CHANNELS_OFFSET / OFFSET_DIV];
      break;
    case SAMPLES_OFFSET:
      assert(is_write == 1);
      printf("device register -- samples writed with %d\n", audio_base[SAMPLES_OFFSET / OFFSET_DIV]);
      s.samples = audio_base[SAMPLES_OFFSET / OFFSET_DIV];
      break;
    case SBUF_SIZE_OFFSET:
      assert(is_write == 0);
      audio_base[SBUF_SIZE_OFFSET / OFFSET_DIV] = CONFIG_SB_SIZE;
      break;
    case INIT_OFFSET:
      if (is_write == 1) {
        if (audio_base[INIT_OFFSET / OFFSET_DIV] == true)
          init_SDL_AudioSpec();
        else
          panic("device/audio.c: Unknown init value");
      } else {
        audio_base[INIT_OFFSET / OFFSET_DIV] = MUXDEF(CONFIG_HAS_AUDIO, true, false);
      }
      break;
    case COUNT_OFFSET:
      assert(is_write == 0);
      audio_base[COUNT_OFFSET / OFFSET_DIV] = sbuf_count;
      break;
    default: panic("device/audio.c: do not support offset = %d", offset);
  }
}

static void audio_sbuf_io_handler(uint32_t offset, int len, bool is_write) {
  assert(is_write == 1);
  assert(len == 1);
  assert(offset < CONFIG_SB_SIZE);
  sbuf_count++;
}

static void audioCallback(void* userdata, Uint8* stream, int len) {
  for (int i = 0; i < len; i++) {
    uint8_t t = read_sbuf();
    stream[i] = t;
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, audio_sbuf_io_handler);
}
