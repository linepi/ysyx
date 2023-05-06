#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12) << 12, 32); } while(0)
#define immS() do { *imm = SEXT((BITS(i, 31, 25) << 5) | BITS(i, 11, 7), 12); } while(0)
#define immUJ() do { \
  uint32_t ct = BITS(i, 31, 12); \
  uint32_t ut = (BITS(ct, 7, 0) << 12) | (BITS(ct, 8, 8) << 11) | (BITS(ct, 18, 9) << 1) | (BITS(ct, 19, 19) << 20); \
  *imm = SEXT(ut, 21); \
} while(0)
#define immSB() do { \
  uint32_t cht = BITS(i, 31, 25); \
  uint32_t clt = BITS(i, 11, 7); \
  uint32_t ut = (BITS(cht, 6, 6) << 12) | (BITS(cht, 5, 0) << 5) | (BITS(clt, 0, 0) << 11) | (BITS(clt, 4, 1) << 1); \
  *imm = SEXT(ut, 13); \
} while(0)
