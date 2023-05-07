module control (
  input clk,
  input [31:0] inst
);
  always @(posedge clk) begin
    case (inst)
      32'b0000000_00001_00000_000_00000_1110011: ebreak();
    endcase
  end
endmodule