#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum inst_t{
    ADDI  ,
    JALR  ,
    LD    ,
    LW    ,
    LH    ,
    LB    ,
    SB    ,
    SH    ,
    SW    ,
    SD    ,
    AUIPC ,
    LUI   ,
    JAL   ,
    LBU   ,
    LHU   ,
    LWU   ,
    SLLI  ,
    SLTI  ,
    SLTIU ,
    XORI  ,
    SRLI  ,
    SRAI  ,
    ORI   ,
    ANDI  ,
    ADDIW ,
    SLLIW ,
    SRLIW ,
    SRAIW ,
    ADD   ,
    SUB   ,
    SLL   ,
    SLT   ,
    SLTU  ,
    XOR   ,
    SRL   ,
    SRA   ,
    OR    ,
    AND   ,
    ADDW  ,
    SUBW  ,
    SLLW  ,
    SRLW  ,
    SRAW  ,
    MUL   ,
    MULH  ,
    MULHU ,
    MULHSU,
    DIV   ,
    DIVU  ,
    REM   ,
    REMU  ,
    MULW  ,
    DIVW  ,
    DIVUW ,
    REMW  ,
    REMUW ,
    BEQ   ,
    BNE   ,
    BLT   ,
    BGE   ,
    BLTU  ,
    BGEU  ,
};

char instname[BGEU + 1][10] = {
    [ADDI] =   "addi"  ,
    [JALR] =   "jalr"  ,
    [LD] =     "ld"    ,
    [LW] =     "lw"    ,
    [LH] =     "lh"    ,
    [LB] =     "lb"    ,
    [SB] =     "sb"    ,
    [SH] =     "sh"    ,
    [SW] =     "sw"    ,
    [SD] =     "sd"    ,
    [AUIPC] =  "auipc" ,
    [LUI] =    "lui"   ,
    [JAL] =    "jal"   ,
    [LBU] =    "lbu"   ,
    [LHU] =    "lhu"   ,
    [LWU] =    "lwu"   ,
    [SLLI] =   "slli"  ,
    [SLTI] =   "slti"  ,
    [SLTIU] =  "sltiu" ,
    [XORI] =   "xori"  ,
    [SRLI] =   "srli"  ,
    [SRAI] =   "srai"  ,
    [ORI] =    "ori"   ,
    [ANDI] =   "andi"  ,
    [ADDIW] =  "addiw" ,
    [SLLIW] =  "slliw" ,
    [SRLIW] =  "srliw" ,
    [SRAIW] =  "sraiw" ,
    [ADD] =    "add"   ,
    [SUB] =    "sub"   ,
    [SLL] =    "sll"   ,
    [SLT] =    "slt"   ,
    [SLTU] =   "sltu"  ,
    [XOR] =    "xor"   ,
    [SRL] =    "srl"   ,
    [SRA] =    "sra"   ,
    [OR] =     "or"    ,
    [AND] =    "and"   ,
    [ADDW] =   "addw"  ,
    [SUBW] =   "subw"  ,
    [SLLW] =   "sllw"  ,
    [SRLW] =   "srlw"  ,
    [SRAW] =   "sraw"  ,
    [MUL] =    "mul"   ,
    [MULH] =   "mulh"  ,
    [MULHU] =  "mulhu" ,
    [MULHSU] = "mulhsu",
    [DIV] =    "div"   ,
    [DIVU] =   "divu"  ,
    [REM] =    "rem"   ,
    [REMU] =   "remu"  ,
    [MULW] =   "mulw"  ,
    [DIVW] =   "divw"  ,
    [DIVUW] =  "divuw" ,
    [REMW] =   "remw"  ,
    [REMUW] =  "remuw" ,
    [BEQ] =    "beq"   ,
    [BNE] =    "bne"   ,
    [BLT] =    "blt"   ,
    [BGE] =    "bge"   ,
    [BLTU] =   "bltu"  ,
    [BGEU] =   "bgeu"  ,
};

struct A {
    int cnt;
    enum inst_t type;
    char instname[10];
    char inst[256];
};

int cmp (const void *a, const void *b) {
   return ((struct A*)b)->cnt - ((struct A*)a)->cnt;
}


int inst_count() {
    FILE* log = fopen("/home/w/dev/ysyx-workbench/am-kernels/kernels/typing-game/build/nemu-log.txt", "r");
    assert(log != NULL);
    FILE* inst = fopen("/home/w/dev/ysyx-workbench/am-kernels/kernels/typing-game/build/inst.txt", "r");
    assert(inst != NULL);
    FILE* out = fopen("/home/w/dev/ysyx-workbench/am-kernels/kernels/typing-game/build/inst_out.txt", "w");
    assert(out != NULL);

    char line[256];
    struct A record[BGEU + 1];

    int i = 0;
    while (fgets(line, sizeof(line), inst) != NULL) {
        record[i].cnt = 0;
        record[i].type = i;
        strcpy(record[i].instname, instname[i]);
        strcpy(record[i].inst, line);
        i++;
    }

    while (fgets(line, sizeof(line), log) != NULL) {
        for (size_t i = 0; i < BGEU + 1; i++) {
            if (strstr(line, record[i].instname) != NULL) {
                record[i].cnt++;
                break;
            }
        }
    }


    qsort(record, BGEU + 1, sizeof(struct A), cmp);
    for (size_t i = 0; i < BGEU + 1; i++) {
        fprintf(out, "%s", record[i].inst);
    }

    for (size_t i = 0; i < BGEU + 1; i++) {
        printf("%s %d\n", record[i].instname, record[i].cnt);
    }

    fclose(log);
    fclose(inst);
    fclose(out);
    return 0;
}