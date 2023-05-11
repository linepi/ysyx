`include "LemonPC/defines.v"
module testbench;
  reg clk;

  wire [63:0] res;
  alu #(64) i0(64'hfffffffffffffff0, 64'h0000000000000000, `alu_sel_lt, res);

  integer i;
  initial begin
    clk = 0;
    i = 0;
  end

  always#10 clk = ~clk;
  always @(posedge clk) begin
    if(i == 1) $finish;
    $display("%0d", res);
    i++;
  end
endmodule