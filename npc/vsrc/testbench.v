module testbench;
  reg clk;

  wire [63:0] res1;
  wire [63:0] res2;
  alu #(64) i0(64'hfffffffffffffff0, 64'h0000000000000000, 4'd8, res);
  alu #(64) i1(64'hfffffffffffffff0, 64'h0000000000000000, 4'd15, res);

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