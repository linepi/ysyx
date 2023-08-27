#include <NDL.h>
#include <SDL.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define keyname(k) #k,

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *event) {
  char buf[100];
  int readed = NDL_PollEvent(buf, sizeof(buf));
  if (readed == 0) return 0;

  char *action = get_key_value(buf, "ACTION");
  if (0 == strcmp(action, "DOWN")) { 
    event->type = SDL_KEYDOWN;
  } else if (0 == strcmp(action, "UP")) {
    event->type = SDL_KEYUP;
  } else {
    assert(0);
  }

  char *code = get_key_value(buf, "CODE");
  event->key.keysym.sym = atoi(code);
  return 1;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[100];
  int readed;
  while ((readed = NDL_PollEvent(buf, sizeof(buf))) == 0);

  char *action = get_key_value(buf, "ACTION");
  if (0 == strcmp(action, "DOWN")) { 
    event->type = SDL_KEYDOWN;
  } else if (0 == strcmp(action, "UP")) {
    event->type = SDL_KEYUP;
  } else {
    assert(0);
  }

  char *code = get_key_value(buf, "CODE");
  event->key.keysym.sym = atoi(code);
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
