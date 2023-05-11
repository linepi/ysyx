`include "defines.v"

module control (
  input clk,
  input [31:0] inst,
  output reg [2:0] imm_sel,
  output reg [3:0] alu_sel,
  output reg alu_a_sel,
  output reg alu_b_sel,
  output reg pc_sel,
  output reg ebreak_flag
);
  always @(*) begin
    ebreak_flag = 0;
    pc_sel = `pc_sel_snpc;
    casez (inst)
      32'b0000000_00001_00000_000_00000_1110011: begin // ebreak
        ebreak_flag = 1;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0010011: begin // addi(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_rs1;
        alu_b_sel = `alu_b_sel_imm;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100111: begin // jalr(I)
        imm_sel = `imm_sel_I;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        pc_sel = `pc_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100111: begin // jal(UJ)
        imm_sel = `imm_sel_UJ;
        alu_sel = `alu_sel_add;
        pc_sel = `pc_sel_alu;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0010111: begin // auipc(U)
        imm_sel = `imm_sel_U;
        alu_sel = `alu_sel_add;
        alu_a_sel = `alu_a_sel_pc;
        alu_b_sel = `alu_b_sel_imm;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0110111: begin // lui(U)
        imm_sel = `imm_sel_U;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0100011: begin // sd(S)
        imm_sel = `imm_sel_S;  
      end
      default: $display("Unspecified control case!");
    endcase
  end
endmodule