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

#include <sdb.h>
#include <utils.h>

static int is_batch_mode = false;
extern struct func_t *functbl;

void init_regex();
void init_wp_pool();
extern void isa_reg_display();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  // why use this?
  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
  if (nemu_state.state == NEMU_ABORT) {
    printf("nemu is aborted\n");
    return 0;
  }
  if (nemu_state.state == NEMU_END) {
    printf("program is ended\n");
    return 0;
  }

  int steps = 1;
  if(args != NULL) {
    steps = atoi(args);
  }
  cpu_exec(steps);

  if (nemu_state.state == NEMU_ABORT) {
    printf("nemu is aborted\n");
    return 0;
  }
  if (nemu_state.state == NEMU_END) {
    printf("program is ended\n");
    return 0;
  }
  IFDEF(CONFIG_ITRACE, frame_dump(cpu.pc, 5));
  return 0;
}

static int cmd_info(char *args) {
  if(args == NULL) {
    printf("Usage: info <r|w>. r --> register, w --> watchpoints.\n");
    return 0;
  }
  switch(args[0]) {
    case 'r':
      isa_reg_display();
      break;
    case 'w':
      wp_display();
      break;
  }
  return 0;
}

static int cmd_x(char *args) {
  char* length = strtok(args, " ");
  args = length + strlen(length) + 1;
  bool success;
  paddr_t paddr = expr(args, &success);
  if (!success) {
    Error("Invalid Expression!\n");
    return 0;
  }
  for(int i = 0; i < atoi(length); i++) {
    assert(PADDR_VALID(paddr + i));
    printf("%02x ", *guest_to_host(paddr + i));
  }
  printf("\n");
  return 0;
}

static int cmd_b(char *args) {
  if (args == NULL) {
    printf("Usage: b <expression>. example: b 0x80000010\n");
    return 0;
  }

  bool success;
  char *buf = (char *)wmalloc(strlen(args) + 7);
  strcpy(buf, "$pc==");
  strcat(buf, args);

  int func_cnt = 0;
  for (int i = 0; !functbl[i].end; i++) {
    if (strcmp(functbl[i].name, args + 1) == 0) {
      func_cnt++;
    }
  }
  if (func_cnt > 1) {
    printf("More than one %s() detected, please choose one below:\n", args + 1);
    for (int i = 0; !functbl[i].end; i++) {
      if (strcmp(functbl[i].name, args + 1) == 0) {
        printf("0x%016lx\n", functbl[i].addr);
      }
    }
    return 0;
  } 

  expr_t val = expr(buf + 5, &success);
  if (!success) {
    Error("Invalid Expression\n");
    return 0;
  }

  WP *new = new_wp();
  memcpy(new->e, buf, strlen(buf) + 1);  // copy args and its end '\0'
  new->val = (cpu.pc == val);
  new->breakpoint = true;
  // breakpoint is a function
  if (args[0] == '&') {
    new->funcName = (char *)wmalloc(strlen(args) + 1); 
    strcpy(new->funcName, args + 1);
  }
  return 0;
}

static int cmd_p(char *args) {
  bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    printf("Invalid Expression.\n");
    return 0;
  }
  printf(EXPR_NUM_FMT"\n", val);
  return 0;
}

static int cmd_px(char *args) {
  bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    Error("Invalid Expression\n");
    return 0;
  }
  printf("0x%lx\n", val);
  return 0;
}

static int cmd_w(char *args) {
  bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    Error("Invalid Expression\n");
    return 0;
  }
  WP *new = new_wp();
  memcpy(new->e, args, strlen(args) + 1);  // copy args and its end '\0'
  new->val = val;
  new->breakpoint = false;
  return 0;
}

static int cmd_del(char *args) {
  int NO = atoi(args);
  assert(NO > 0 && NO <= 32);
  WP *i;
  for (i = get_wp_head(); i; i = i->next) {
    if (NO == i->NO) {
      free_wp(i);
      break;
    }
  }
  if (!i) {
    Error("Watchpoint %d does not exist.\n", NO);
  }
  return 0;
}

static int cmd_bt(char *args) { 
  IFNDEF(CONFIG_ITRACE, printf("ITRACE disabled, open it before backtrace\n"); return 0;);
  backtrace();
  return 0;
}

static int cmd_pt(char *args) { 
  IFNDEF(CONFIG_ITRACE, printf("ITRACE disabled, open it before pc trace\n"); return 0;);
  if (args == NULL) {
    printf("Usage: pt [N]. pc trace.\n");
    return 0;
  }
  pc_trace_dump(atoi(args));
  return 0;
}

static int cmd_list(char *args) {
  if (nemu_state.state == NEMU_ABORT) {
    printf("nemu is aborted\n");
    return 0;
  }
  if (nemu_state.state == NEMU_END) {
    printf("program is ended\n");
    return 0;
  }

  if (args == NULL) {
    printf("Usage: list -i [N] or list -f. Show N instruction with default 1 or show functions\n");
    return 0;
  }
  if (*args == '\0' || *args != '-') {
    printf("Usage: list -i [N] or list -f. Show N instruction with default 1 or show functions\n");
    return 0;
  }

  while (*args++ == '-');
  args--;
  if (*args == 'i') {
    while (*args++ == ' ');
    IFDEF(CONFIG_ITRACE, frame_dump(cpu.pc, MAX(atoi(args), 1)));
  } else if (*args == 'f') {
    func_list();
  } else {
    printf("Usage: list -i [N] or list -f. Show N instruction with default 1 or show functions\n");
  }
  return 0;
}

int cmp(const void* a, const void* b) {
  return ((struct func_t*)b)->cnt - ((struct func_t*)a)->cnt;
}

int cmd_analise() {
  IFNDEF(CONFIG_ITRACE, printf("ITRACE disabled, open it before backtrace\n"); return 0;);
  printf("Function Name                 Call Count:\n");
  int i;
  for (i = 0; !functbl[i].end; i++);
  qsort(functbl, i, sizeof(struct func_t), cmp);
  int space = 30;
  for (i = 0; !functbl[i].end; i++) {
    printf("%s", functbl[i].name);
    int len = strlen(functbl[i].name);
    for (int j = 0; j < space - len; j++) putchar(' ');
    printf("%ld\n", functbl[i].cnt);
  }
  return 0;
}

int cmd_reboot() {
  void clear_mem();
  clear_mem();
  void clear_reg();
  clear_reg();
  init_isa();
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "   Display information about all supported commands", cmd_help },
  { "c", "      Continue the execution of the program", cmd_c },
  { "q", "      Exit NEMU", cmd_q },
  { "si", "     Usage: si [N]. Step N instruction, default 1. ", cmd_si },
  { "info", "   Usage: info <r|w>. r --> register, w --> watch points. ", cmd_info },
  { "x", "      Usage: x <number of bytes> <expression>. example: x 10 0x80000000 ", cmd_x },
  { "p", "      Usage: p <expression>. example: p $s0 + 5 ", cmd_p },
  { "p/x", "    Usage: p/x <expression>. example: p/x $s0 + 5 ", cmd_px },
  { "w", "      Usage: w <expression>. example: w $s0 + 5 ", cmd_w },
  { "b", "      Usage: b <expression>. example: b 0x80000010", cmd_b },
  { "bt", "     Usage: bt", cmd_bt },
  { "pt", "     Usage: pt [N]. pc trace.", cmd_pt },
  { "del", "    Usage: del <watchpoint NO>. example: d 2", cmd_del },
  { "list", "   Usage list -i [N] or list -f. Show N instruction with default 1 or show functions", cmd_list},
  { "analise", "analise the performance", cmd_analise},
  { "reboot", " reboot nemu", cmd_reboot},
};


#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf(ANSI_FMT("%s", ANSI_FG_GREEN)" %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf(ANSI_FMT("%s", ANSI_FG_GREEN)" - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  char command_cache[512]; command_cache[0] = '\0';
  char str_cache[512]; str_cache[0] = '\0';
  int nullcmd;

  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);
    strcpy(str_cache, str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { 
      if (command_cache[0] == '\0') continue;
      nullcmd = 1;
      strcpy(str_cache, command_cache);
      str_end = str_cache + strlen(str_cache);
      cmd = strtok(str_cache, " ");
    } else {
      nullcmd = 0;
    }


    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {

        if (cmd_table[i].handler(args) < 0) { 
          nemu_state.state = NEMU_QUIT;
          return; 
        }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    /* command cache */
    if (nullcmd == 0)
      strcpy(command_cache, str_cache);
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
