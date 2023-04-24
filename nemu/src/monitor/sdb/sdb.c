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

#include <isa.h>
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/paddr.h>
#include <sdb.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
extern void isa_reg_display();
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

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
  int steps = 1;
  if(args != NULL) {
    steps = atoi(args);
  }
  cpu_exec(steps);

  char disa[128];
  vaddr_t pc = cpu.pc - 8;
  for (int i = 0; i < 5; i++) {
    uint32_t inst = inst_fetch_add(&pc, 4);
    disassemble(disa, 128, pc, (uint8_t *)&inst, 4);
    puts(disa);
  }
  return 0;
}

static int cmd_info(char *args) {
  if(args == NULL) {
    printf("Usage: info <r|w>. r --> register, w --> watch points.\n");
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

static int cmd_p(char *args) {
  bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    Error("Invalid Expression\n");
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

static int cmd_list(char *args) {
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Usage: si [N]. Step N instruction, default 1. ", cmd_si },
  { "info", "Usage: info <r|w>. r --> register, w --> watch points. ", cmd_info },
  { "x", "Usage: x <number of bytes> <expression>. example: x 10 0x80000000 ", cmd_x },
  { "p", "Usage: p <expression>. example: p $s0 + 5 ", cmd_p },
  { "p/x", "Usage: p/x <expression>. example: p/x $s0 + 5 ", cmd_px },
  { "w", "Usage: w <expression>. example: w $s0 + 5 ", cmd_w },
  { "del", "Usage: del <watchpoint NO>. example: d 2", cmd_del },
  { "list", "Usage list [N]. Show N instruction, default 1", cmd_list},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
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
