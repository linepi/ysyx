`include "defines.v"

module control (
  input [31:0] inst,
  input b_eq,
  input b_lt,
  input b_ltu,
  output reg pc_sel,
  output reg ebreak_flag,
  output reg [2:0] imm_sel,
  output reg [4:0] alu_sel,
  output reg [1:0] alu_a_sel,
  output reg [2:0] mem_r_sel,
  output reg alu_b_sel,
  output reg reg_wen,
  output reg mem_wen,
  output reg mem_ren,
  output reg [7:0] mem_mask,
  output reg [1:0] reg_w_sel
);
  always @(*) begin
    pc_sel = `pc_sel_snpc;
    ebreak_flag = `false;

    reg_wen = `false;
    mem_wen = `false;
    mem_ren = `false;
    casez (inst)
      32'b0000000_00001_00000_000_00000_1110011: begin // ebreak
        ebreak_flag = `true;
      end
      // ===================== R ==========================
      32'b0000000_zzzzz_zzzzz_000_zzzzz_0110011: begin // add(R)
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0100000_zzzzz_zzzzz_000_zzzzz_0110011: begin // sub(R)
        alu_sel = `alu_sel_sub;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_111_zzzzz_0110011: begin // and(R)
        alu_sel = `alu_sel_and;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_001_zzzzz_0110011: begin // sll(R)
        alu_sel = `alu_sel_sll;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_110_zzzzz_0110011: begin // or(R)
        alu_sel = `alu_sel_or;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_100_zzzzz_0110011: begin // xor(R)
        alu_sel = `alu_sel_xor;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_101_zzzzz_0110011: begin // srl(R)
        alu_sel = `alu_sel_srl;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0100000_zzzzz_zzzzz_101_zzzzz_0110011: begin // sra(R)
        alu_sel = `alu_sel_sra;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_010_zzzzz_0110011: begin // slt(R)
        alu_sel = `alu_sel_lt;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_011_zzzzz_0110011: begin // sltu(R)
        alu_sel = `alu_sel_ltu;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_000_zzzzz_0111011: begin // addw(R)
        alu_sel = `alu_sel_addw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0100000_zzzzz_zzzzz_000_zzzzz_0111011: begin // subw(R)
        alu_sel = `alu_sel_subw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_001_zzzzz_0111011: begin // sllw(R)
        alu_sel = `alu_sel_sllw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_101_zzzzz_0111011: begin // srlw(R)
        alu_sel = `alu_sel_srlw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0100000_zzzzz_zzzzz_101_zzzzz_0111011: begin // sraw(R)
        alu_sel = `alu_sel_sraw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_000_zzzzz_0110011: begin // mul(R)
        alu_sel = `alu_sel_mul;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_100_zzzzz_0110011: begin // div(R)
        alu_sel = `alu_sel_div;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_101_zzzzz_0110011: begin // divu(R)
        alu_sel = `alu_sel_divu;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_110_zzzzz_0110011: begin // rem(R)
        alu_sel = `alu_sel_rem;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_111_zzzzz_0110011: begin // remu(R)
        alu_sel = `alu_sel_remu;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_000_zzzzz_0111011: begin // mulw(R)
        alu_sel = `alu_sel_mulw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_100_zzzzz_0111011: begin // divw(R)
        alu_sel = `alu_sel_divw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_101_zzzzz_0111011: begin // divuw(R)
        alu_sel = `alu_sel_divuw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_110_zzzzz_0111011: begin // remw(R)
        alu_sel = `alu_sel_remw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000001_zzzzz_zzzzz_111_zzzzz_0111011: begin // remuw(R)
        alu_sel = `alu_sel_remuw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      // ================= SB ======================
      32'bzzzzzzz_zzzzz_zzzzz_100_zzzzz_1100011: begin // blt(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & b_lt;
      end
      32'bzzzzzzz_zzzzz_zzzzz_101_zzzzz_1100011: begin // bge(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & (~b_lt);
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100011: begin // beq(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & b_eq;
      end
      32'bzzzzzzz_zzzzz_zzzzz_001_zzzzz_1100011: begin // bne(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & (~b_eq);
      end
      32'bzzzzzzz_zzzzz_zzzzz_110_zzzzz_1100011: begin // bltu(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & b_ltu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_111_zzzzz_1100011: begin // bgeu(SB)
        imm_sel = `imm_sel_SB;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu & (~b_ltu);
      end
      // ================= S =======================
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0100011: begin // sb
        imm_sel = `imm_sel_S;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_wen = `true;
        mem_mask = `mem_mask_b;
      end
      32'bzzzzzzz_zzzzz_zzzzz_001_zzzzz_0100011: begin // sh
        imm_sel = `imm_sel_S;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_wen = `true;
        mem_mask = `mem_mask_h;
      end
      32'bzzzzzzz_zzzzz_zzzzz_010_zzzzz_0100011: begin // sw
        imm_sel = `imm_sel_S;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_wen = `true;
        mem_mask = `mem_mask_w;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0100011: begin // sd
        imm_sel = `imm_sel_S;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_wen = `true;
        mem_mask = `mem_mask_d;
      end
      // =============== I =============================
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0010011: begin // addi(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0011011: begin // addiw(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_addw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b000000z_zzzzz_zzzzz_001_zzzzz_0010011: begin // slli(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_sll;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b000000z_zzzzz_zzzzz_101_zzzzz_0010011: begin // srli(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_srl;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_100_zzzzz_0010011: begin // xori(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_xor;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b010000z_zzzzz_zzzzz_101_zzzzz_0010011: begin // srai(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_sra;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_110_zzzzz_0010011: begin // ori(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_or;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_111_zzzzz_0010011: begin // andi(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_and;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_001_zzzzz_0011011: begin // slliw(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_sllw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_101_zzzzz_0011011: begin // srliw(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_srlw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0100000_zzzzz_zzzzz_101_zzzzz_0011011: begin // sraiw(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_sraw;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_010_zzzzz_0010011: begin // slti(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_lt;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0010011: begin // sltiu(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_ltu;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100111: begin // jalr(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_pc;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0000011: begin // lb(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_b;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_001_zzzzz_0000011: begin // lh(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_h;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_010_zzzzz_0000011: begin // lw(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_w;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0000011: begin // ld(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_d;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_100_zzzzz_0000011: begin // lbu(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_bu;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_101_zzzzz_0000011: begin // lhu(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_hu;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end
      32'bzzzzzzz_zzzzz_zzzzz_110_zzzzz_0000011: begin // lwu(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_ren = `true;
        mem_r_sel = `mem_r_sel_wu;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_mem;
      end

      // =============== UJ and U ========================
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_1101111: begin // jal(UJ)
        imm_sel = `imm_sel_UJ;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        pc_sel = `pc_sel_alu;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_pc;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0010111: begin // auipc(U)
        imm_sel = `imm_sel_U;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0110111: begin // lui(U)
        imm_sel = `imm_sel_U;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_zero;
        alu_b_sel = `alu_b_sel_imm;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end            
      32'd0: begin
      end
      default: begin
        ebreak_flag = `true;
        $display("Unspecified control case: %b", inst);
      end
    endcase
  end
endmodule