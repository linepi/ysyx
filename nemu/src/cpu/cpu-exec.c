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
***************************************************************#include <cpu/cpu.h>************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <sdb.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
CPU_state last_cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this) {
#ifdef CONFIG_ITRACE
  char *p = _this->logbuf;
  p += snprintf(p, sizeof(_this->logbuf), FMT_WORD ":", _this->pc);
  int ilen = _this->snpc - _this->pc;
  int i;
  uint8_t *inst = (uint8_t *)&_this->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, _this->logbuf + sizeof(_this->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, _this->snpc, _this->pc), (uint8_t *)&_this->isa.inst.val, ilen);

  log_write("%s\n", _this->logbuf); 
  pc_trace();
  if (image_elf_fp) ftrace();
#endif

  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, _this->dnpc));

#ifdef CONFIG_WATCHPOINT
  // watch point check
  for (WP *i = get_wp_head(); i; i = i->next) {
    bool success;
    expr_t val = expr(i->e, &success);
    if (!success) {
      Error("Invalid expression\n");
      continue;
    }
    if (i->breakpoint) {
      if (val == 1) {
        printf(ANSI_FMT("Hit ", ANSI_FG_BLUE));
        if (i->funcName == NULL) {
          printf("%s\n", i->e + 5);
        } else {
          printf("%s()\n", i->funcName);
        }
        frame_dump(5);
        nemu_state.state = NEMU_STOP;
      } 
    } else {
      if (val != i->val) {
        printf(ANSI_FMT("hit watchpoint %d:", ANSI_FG_BLUE)" %s\n", i->NO, i->e);
        printf("old val: "EXPR_NUM_FMT"\n", i->val);
        printf("new val: "EXPR_NUM_FMT"\n", val);
        printf(ANSI_FMT("changed at: ", ANSI_FG_BLUE));
        puts(_this->logbuf);
        i->val = val;
      }
    }
  }
#endif
}

static void exec_once(Decode *s) {
  IFDEF(CONFIG_ITRACE, last_cpu = cpu);
  s->pc = cpu.pc;
  s->snpc = cpu.pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
}

static void execute(uint64_t n) {
  Decode s;
  for (; n > 0; n--) {
    exec_once(&s);
    trace_and_difftest(&s);
    g_nr_guest_inst++;
    if (nemu_state.state != NEMU_RUNNING) break;
    // update device only when every 0xff instuctions have been executed.
    // this is to improve performance, because get_time() consume so much.
    if ((g_nr_guest_inst & 0xff) != 0) continue;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  IFDEF(CONFIG_ITRACE, backtrace());
  isa_reg_display();
  IFDEF(CONFIG_ITRACE, pc_trace_dump(20));
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
