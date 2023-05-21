module testbench;
  reg clk;

  integer i;
  initial begin
    clk = 0;
    i = 0;
  end

  always#10 clk = ~clk;
  always @(posedge clk) begin
    if(i == 1) $finish;
    $display("%0d", res1);
    $display("%0d", res2);
    i++;
  end
endmodule