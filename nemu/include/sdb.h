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

#ifndef __SDB_H__
#define __SDB_H__

#include <isa.h>
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/paddr.h>
#include <common.h>
#include <elf.h>

#define NR_WP 32
typedef sword_t expr_t;
#define EXPR_NUM_FMT "%ld"

// watchpoint.h
typedef struct watchpoint {
  int NO;
  bool breakpoint;
  char *funcName;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char e[256];
  expr_t val;
} WP;


expr_t expr(char *e, bool *success);
WP* new_wp();
void free_wp(WP *wp);
WP* get_wp_head();
void wp_display();
void clear_wp();

// elf related declaration
#define FUNC_LEN 64

extern FILE *elf_fp;
struct elfinfo_t {
  Elf64_Ehdr Ehdr;
  Elf64_Shdr *Shdr;
  Elf64_Shdr *Shdr_symtab;
  Elf64_Shdr *Shdr_strtab;
  Elf64_Shdr *Shdr_shstrtab;

  size_t nr_sym;
  Elf64_Sym *Sym;
};

void init_elf(const char* elf_file);
bool is_elf(FILE *e);
extern struct elfinfo_t elfinfo;

// trace.h
#define NR_PC_ROAD 100

struct func_t {
  bool end; 
  word_t addr;
  int size;
  uint64_t cnt;
  char name[FUNC_LEN];
};

struct func_stack_t {
  struct func_t *func;
  struct func_stack_t *next;
  struct func_stack_t *pre;
};

struct pc_road {
  vaddr_t arr[NR_PC_ROAD];
  int cur;
  bool initialised;
};

void frame_dump(vaddr_t pc, int n);
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void make_functbl();
void func_list();
void backtrace();
void pc_trace(vaddr_t pc);
void pc_trace_dump(int n);
void ftrace(vaddr_t pc);
void clear_funcstack();
extern struct func_t *functbl;

#endif
