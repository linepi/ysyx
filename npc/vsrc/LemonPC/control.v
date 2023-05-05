module control (
  input [31:0] inst,
  output ebreak
);
  always @(*) begin
    case (inst)
      32'b0000000 00001 00000 000 00000 1110011: ebreak = 1'b1;
      default: ebreak = 1'b0;
    endcase
  end
endmodule