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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, 
  TYPE_UJ, TYPE_R, TYPE_SB,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
// UJ imm format: 31~12: [20|10:1|11|19:12]
#define immUJ() do { \
  uint32_t ct = BITS(i, 31, 12); \
  uint32_t ut = (BITS(ct, 7, 0) << 12) | (BITS(ct, 8, 8) << 11) | (BITS(ct, 18, 9) << 1) | (BITS(ct, 19, 19) << 20); \
  *imm = SEXT(ut, 20); \
} while(0)
// SB imm format: 31~25: [12|10:5], 11~7: [4:1|11]
#define immSB() do { \
  uint32_t cht = BITS(i, 31, 25); \
  uint32_t clt = BITS(i, 11, 7); \
  uint32_t ut = (BITS(cht, 6, 6) << 12) | (BITS(cht, 5, 0) << 5) | (BITS(clt, 0, 0) << 11) | (BITS(clt, 4, 1) << 1); \
  *imm = SEXT(ut, 12); \
} while(0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_R: src1R(); src2R(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_UJ: immUJ(); break;
    case TYPE_SB: src1R(); src2R(); immSB(); break;
  }
}

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  // why? something to be implemented?
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  // ==========   I ============
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   ,  I, R(rd) = s->pc + 4; s->dnpc = src1 + imm);
  INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld     ,  I, R(rd) = SEXT(Mr(src1 + imm, 8), 64));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     ,  I, R(rd) = SEXT(Mr(src1 + imm, 4), 32));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     ,  I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     ,  I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    ,  I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    ,  I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 110 ????? 00000 11", lwu    ,  I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   ,  I, R(rd) = src1 + imm);
  INSTPAT("000000? ????? ????? 001 ????? 00100 11", slli   ,  I, R(rd) = src1 << imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   ,  I, R(rd) = (sword_t)src1 < (sword_t)imm);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  ,  I, R(rd) = src1 < imm);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   ,  I, R(rd) = src1 ^ imm);
  INSTPAT("000000? ????? ????? 101 ????? 00100 11", srli   ,  I, R(rd) = src1 >> imm);
  INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai   ,  I, R(rd) = (sword_t)src1 >> imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    ,  I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   ,  I, R(rd) = src1 & imm);
  INSTPAT("??????? ????? ????? 000 ????? 00110 11", addiw  ,  I, R(rd) = SEXT((src1 & 0xFFFFFFFF) + imm, 32));
  INSTPAT("0000000 ????? ????? 001 ????? 00110 11", slliw  ,  I, R(rd) = SEXT((src1 & 0xFFFFFFFF) << imm, 32));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srliw  ,  I, R(rd) = SEXT((uint32_t)src1 >> imm, 32));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", sraiw  ,  I, R(rd) = SEXT((int32_t)src1 >> imm, 32));
  // ============== R ==============
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    ,  R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    ,  R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    ,  R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    ,  R, R(rd) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   ,  R, R(rd) = src1 < src2);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    ,  R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    ,  R, R(rd) = src1 >> src2);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    ,  R, R(rd) = (sword_t)src2 >> src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     ,  R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    ,  R, R(rd) = src1 & src2);
  INSTPAT("0000000 ????? ????? 000 ????? 01110 11", addw   ,  R, R(rd) = (sword_t)((int32_t)src1 + (int32_t)src2));
  INSTPAT("0100000 ????? ????? 000 ????? 01110 11", subw   ,  R, R(rd) = (sword_t)((int32_t)src1 - (int32_t)src2));
  INSTPAT("0000000 ????? ????? 001 ????? 01110 11", sllw   ,  R, R(rd) = (sword_t)((int32_t)src1 << (int32_t)src2));
  INSTPAT("0000000 ????? ????? 101 ????? 01110 11", srlw   ,  R, R(rd) = (sword_t)(int32_t)((uint32_t)src1 >> (int32_t)src2));
  INSTPAT("0100000 ????? ????? 101 ????? 01110 11", sraw   ,  R, R(rd) = (sword_t)(int32_t)src2 >> (int32_t)src2);

  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    ,  R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   ,  R, R(rd) = 1);
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhu  ,  R, R(rd) = 1);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhsu ,  R, R(rd) = 1);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    ,  R, R(rd) = src2 != 0 ? (sword_t)src1 / (sword_t)src2 : -1);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   ,  R, R(rd) = src2 != 0 ? src1 / src2 : -1);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    ,  R, R(rd) = src2 != 0 ? (sword_t)src1 % (sword_t)src2 : src1);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   ,  R, R(rd) = src2 != 0 ? src1 % src2: src1);
  INSTPAT("0000001 ????? ????? 000 ????? 01110 11", mulw   ,  R, R(rd) = (sword_t)((int32_t)src1 * (int32_t)src2));
  INSTPAT("0000001 ????? ????? 100 ????? 01110 11", divw   ,  R, R(rd) = src2 != 0 ? (sword_t)((int32_t)src1 / (int32_t)src2) : -1);
  INSTPAT("0000001 ????? ????? 101 ????? 01110 11", divuw  ,  R, R(rd) = src2 != 0 ? (sword_t)(int32_t)((uint32_t)src1 / (uint32_t)src2) : -1);
  INSTPAT("0000001 ????? ????? 110 ????? 01110 11", remw   ,  R, R(rd) = src2 != 0 ? (sword_t)((int32_t)src1 % (int32_t)src2) : (sword_t)(int32_t)src1);
  INSTPAT("0000001 ????? ????? 111 ????? 01110 11", remuw  ,  R, R(rd) = src2 != 0 ? (sword_t)(int32_t)((int32_t)src1 % (int32_t)src2) : (sword_t)(int32_t)src1);
  // ============== S ================
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     ,  S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     ,  S, Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     ,  S, Mw(src1 + imm, 4, src2));
  INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     ,  S, Mw(src1 + imm, 8, src2));
  // ============== U =================
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  ,  U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    ,  U, R(rd) = imm);
  // ============== UJ ================
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , UJ, R(rd) = s->pc + 4; s->dnpc = s->pc + imm);
  // ============== SB ================
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , SB, s->dnpc = src1 == src2 ? s->pc + imm : s->snpc);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , SB, s->dnpc = src1 != src2 ? s->pc + imm : s->snpc);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , SB, s->dnpc = (sword_t)src1 < (sword_t)src2 ? s->pc + imm : s->snpc);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , SB, s->dnpc = (sword_t)src1 >= (sword_t)src2 ? s->pc + imm : s->snpc);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , SB, s->dnpc = src1 < src2 ? s->pc + imm : s->snpc);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , SB, s->dnpc = src1 >= src2 ? s->pc + imm : s->snpc);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak ,  N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    ,  N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
