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
#define CHANNELS_OFFSET 1
#define SAMPLES_OFFSET 2
#define SBUF_SIZE_OFFSET 3
#define INIT_OFFSET 4
#define COUNT_OFFSET 5

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  switch (offset) {
    case FREQ_OFFSET:
      printf("device register -- freq writed with %d\n", audio_base[FREQ_OFFSET]);
      break;
    case CHANNELS_OFFSET:
      printf("device register -- channels writed with %d\n", audio_base[CHANNELS_OFFSET]);
      break;
    case SAMPLES_OFFSET:
      printf("device register -- samples writed with %d\n", audio_base[SAMPLES_OFFSET]);
      break;
    case SBUF_SIZE_OFFSET:
      audio_base[SBUF_SIZE_OFFSET] = CONFIG_SB_ADDR;
      break;
    case INIT_OFFSET:
      break;
    case COUNT_OFFSET:
      audio_base[COUNT_OFFSET] = 0;
      break;
    default: panic("device/Audio.c: do not support offset = %d", offset);
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
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
