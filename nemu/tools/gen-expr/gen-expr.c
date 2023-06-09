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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define NUM_FMT "%ld"

// this should be enough
static char buf[65536] = {};
static int idx = 0;
static char outbuf[65536] = {};
static int outidx = 0;
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  long result = %s; "
"  printf(\"%%ld\", result); "
"  return 0; "
"}";

static int choose(int n) {
  return rand() % n;
}

static void gen_num() {
  // long random_l = ((long int)rand() << 32) | rand();
  sprintf(buf + idx, "(long)");
  idx = strlen(buf);

  long random_l = rand() % 10000 + 1;

  sprintf(buf + idx, NUM_FMT, random_l);
  idx = strlen(buf);

  sprintf(outbuf + outidx, NUM_FMT, random_l);
  outidx = strlen(outbuf);
}

static void gen(char c) {
  sprintf(buf + idx, "%c", c);
  idx = strlen(buf);

  sprintf(outbuf + outidx, "%c", c);
  outidx = strlen(outbuf);
}

static void gen_rand_op() {
  switch (choose(5)) {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    case 3: gen('/'); break;
    case 4: gen('%'); break;
    // case 5: gen('^'); break;
    // case 6: gen('|'); break;
    // case 7: gen('&'); break;
    // case 8: gen('<'); gen('<'); break;
    // case 9: gen('>'); gen('>'); break;
    default: gen('+'); break;
  }
}

static void gen_rand_1op() {
  switch (choose(1)) {
    case 0: gen('~'); break;
  }
}

static void gen_rand_expr() {
  if (choose(3)) gen(' ');

  int cs = choose(8);
  if (idx >= 100) cs = 0;
  switch (cs) {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    // case 2: gen_rand_1op(); gen_rand_expr(); break;
    default: 
      gen_rand_expr(); 
      gen_rand_op(); 
      gen_rand_expr(); 
      break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    idx = 0;
    outidx = 0;
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -w /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    long result;
    fscanf(fp, NUM_FMT, &result);
    pclose(fp);

    // printf(NUM_FMT " %s\n", result, buf);
    printf(NUM_FMT " %s\n", result, outbuf);
  }
  return 0;
}
