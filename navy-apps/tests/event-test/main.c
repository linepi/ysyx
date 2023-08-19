#include <stdio.h>
#include <NDL.h>

int main() {
  NDL_Init(0);
  char buf[64];
  while (1) {
    int readed;
    if (readed = NDL_PollEvent(buf, sizeof(buf))) {
      printf("readed = %d, receive event: %s\n", readed, buf);
    }
  }
  return 0;
}
