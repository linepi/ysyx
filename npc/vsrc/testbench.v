module testbench;
  reg clk;
  reg [7:0] res;
  always#10 clk = ~clk;
  random_8 random_8_ins(.clk(clk), .res(res));
  initial begin
    clk = 0;
  end
  always @(posedge clk) begin
    $display("%b", res);
  end
endmodule