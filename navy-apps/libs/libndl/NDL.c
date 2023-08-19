#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;
static int system_w = 0, system_h = 0;

static char *get_key_value(const char *buf, const char *key) {
  const char *enter;
  const char *colon;
  while (*buf) {
    enter = buf;
    colon = buf;
    while (*colon != ':') {
      colon++;
    }
    while (*enter != '\n') {
      enter++;
    }

    const char *start = buf;
    while (*start == ' ' || *start == '\t') {
      start++;
    }
    const char *end = start;
    while (*end != ' ' && *end != '\t') {
      end++;
    }
    assert(end <= colon);

    char tmpbuf[64];
    memcpy(tmpbuf, start, end - start);
    tmpbuf[end - start] = 0;
    // match
    if (strcmp(tmpbuf, key) == 0) {
      start = colon + 1; 
      while (*start == ' ' || *start == '\t') {
        start++;
      }
      end = start;
      while (*end != '\n' && *end != ' ' && *end != '\t') {
        end++;
      }
      assert(end <= enter);

      char *ret = malloc(end - start + 1);
      memcpy(ret, start, end - start);
      ret[end - start] = 0;
      return ret;
    }
    buf = enter + 1;
  }
  return NULL;
}

uint32_t NDL_GetTicks() {
  struct timeval tmp;
  gettimeofday(&tmp, NULL);
  return tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
}

int NDL_PollEvent(char *buf, int len) {
  // static bool init = false;
  // static FILE *fe;
  // if (!init) {
  //   fe = fopen("/dev/events", "r+");
  //   init = true;
  // }

  // FILE *fe = fopen("/dev/events", "r");
  // assert(fe);
  // fseek(fe, 0, SEEK_SET);
  // int readed = fread(buf, 1, len, fe); 

  int fd = open("/dev/events", 0);
  int readed = read(fd, buf, len);

  // printf("NDL_PollEvent: read %d into buf(max %d)\n", readed, len);
  return readed;
}

void NDL_OpenCanvas(int *w, int *h) {
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w; screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  }
  int fd = open("/proc/dispinfo", 0);
  char buf[64];
  int readed = read(fd, buf, sizeof(buf));

  char *width = get_key_value(buf, "WIDTH");
  char *height = get_key_value(buf, "HEIGHT");
  system_w = atoi(width);
  system_h = atoi(height);

  if (*w == 0 && *h == 0) {
    *w = system_w;
    *h = system_h;
  }
  assert(*w <= system_w && *h <= system_h);
  screen_w = *w; screen_h = *h;

  free(width);
  free(height);
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  int fd = open("/dev/fb", 0);
  int more_x = (system_w - screen_w) / 2;
  int more_y = (system_h - screen_h) / 2;
  for (int yi = y; yi < y + h; yi++) {
    int actual_x = x + more_x;
    int actual_y = yi + more_y;
    lseek(fd, (actual_y * system_w + actual_x) * 4, SEEK_SET);
    write(fd, pixels, 4 * w);
    pixels += w;
  }
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }
  return 0;
}

void NDL_Quit() {
}
