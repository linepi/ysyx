`include "defines.v"

module control (
  input clk,
  input [31:0] inst,
  output reg [2:0] imm_sel,
  output reg [3:0] alu_sel,
  output reg pc_sel,
  output reg ebreak_flag
);
  always @(*) begin
    ebreak_flag = 0;
    pc_sel = 0;
    casez (inst)
      32'b0000000_00001_00000_000_00000_1110011: begin // ebreak
        ebreak_flag = 1;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0010011: begin // addi
        imm_sel = `imm_sel_I;
        alu_sel = 4'd0;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100111: begin // jalr
        imm_sel = `imm_sel_I;
        alu_sel = 4'd0;
        pc_sel = 1;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_1100111: begin // jal
        imm_sel = `imm_sel_UJ;
        alu_sel = 4'd0;
        pc_sel = 1;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0010111: begin // auipc
        imm_sel = `imm_sel_U;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0110111: begin // lui
        imm_sel = `imm_sel_U;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0100011: begin // sd
        imm_sel = `imm_sel_S;  
      end
      default: $display("Unspecified control case!");
    endcase
  end
endmodule