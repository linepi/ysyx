module testbench;
  reg clk;
  reg [7:0] res;
  random_8 random_8_ins(.clk(clk), .res(res));
  integer i;

  initial begin
    clk = 0;
    i = 0;
  end

  always#10 clk = ~clk;
  always @(posedge clk) begin
    if(res == 8'b10000101 && i != 0) $finish;
    $display("%0.d: %b", i, res);
    i++;
  end
endmodule