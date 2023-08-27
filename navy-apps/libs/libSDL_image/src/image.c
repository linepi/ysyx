#define SDL_malloc  malloc
#define SDL_free    free
#define SDL_realloc realloc

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"

SDL_Surface* IMG_Load_RW(SDL_RWops *src, int freesrc) {
  assert(src->type == RW_TYPE_MEM);
  assert(freesrc == 0);
  return NULL;
}

SDL_Surface* IMG_Load(const char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("IMG_Load: error open file\n");
    return NULL;
  }
  fseek(f, 0, SEEK_END);
  int file_size = ftell(f);
  printf("file_size = %d\n", file_size);
  unsigned char *buffer = malloc(file_size);
  if (fread(buffer, 1, file_size, f) != file_size) {
    printf("IMG_Load: fread error\n");
    return NULL;
  }

  SDL_Surface *res = STBIMG_LoadFromMemory(buffer, file_size);
  fclose(f);
  free(buffer);
  return res;
}

int IMG_isPNG(SDL_RWops *src) {
  return 0;
}

SDL_Surface* IMG_LoadJPG_RW(SDL_RWops *src) {
  return IMG_Load_RW(src, 0);
}

char *IMG_GetError() {
  return "Navy does not support IMG_GetError()";
}
