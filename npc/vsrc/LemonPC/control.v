`include "defines.v"

module control (
  input clk,
  input [31:0] inst,
  output reg pc_sel,
  output reg ebreak_flag,
  output reg [2:0] imm_sel,
  output reg [3:0] alu_sel,
  output reg alu_a_sel,
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
      32'b0000000_zzzzz_zzzzz_100_zzzzz_0110011: begin // srl(R)
        alu_sel = `alu_sel_srl;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'b0000000_zzzzz_zzzzz_100_zzzzz_0110011: begin // sra(R)
        alu_sel = `alu_sel_sra;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_rs2;
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0010011: begin // addi(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
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
        reg_wen = `true;
        reg_w_sel = `reg_w_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0100011: begin // sd(S)
        imm_sel = `imm_sel_S;  
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
        mem_wen = `true;
        mem_mask = `mem_mask_d;
      end
      default: $display("Unspecified control case!");
    endcase
  end
endmodule