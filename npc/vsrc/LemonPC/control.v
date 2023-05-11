module control (
  input clk,
  input [31:0] inst,
  output reg [2:0] imm_sel,
  output reg ebreak_flag
);
  always @(*) begin
    ebreak_flag = 0;
    casez (inst)
      32'b0000000_00001_00000_000_00000_1110011: begin // ebreak
        ebreak_flag = 1;
      end
      32'bzzzzzzz_zzzzz_zzzzz_000_zzzzz_0010011: begin // addi
        imm_sel = 3'b001;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0010111: begin // auipc
        imm_sel = 3'b011;
      end
      32'bzzzzzzz_zzzzz_zzzzz_zzz_zzzzz_0110111: begin // lui
        imm_sel = 3'b011;
      end
      32'bzzzzzzz_zzzzz_zzzzz_011_zzzzz_0100011: begin // sd
        imm_sel = 3'b001;  
      end
      default: $display("Unspecified control case!");
    endcase
  end
endmodule