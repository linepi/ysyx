#include <stdio.h>
#include <assert.h>
#include <fixedptc.h>

int main() {
  int a = fixedpt_toint(fixedpt_ceil(fixedpt_rconst(3.5)));
  int b = fixedpt_toint(fixedpt_ceil(fixedpt_rconst(3.4))); 
  int c = fixedpt_toint(fixedpt_ceil(fixedpt_rconst(2.6))); 
  int d = fixedpt_toint(fixedpt_ceil(fixedpt_rconst(0)));
  printf("%d %d %d %d\n", a,b,c,d);
  return 0;
}
