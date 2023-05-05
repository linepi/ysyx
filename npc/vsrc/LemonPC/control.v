module control (
  input [31:0] inst,
  output reg ebreak
);
  always @(*) begin
    case (inst)
      32'b0000000_00001_00000_000_00000_1110011: ebreak = 1'b1;
      default: ebreak = 1'b0;
    endcase
  end
endmodule