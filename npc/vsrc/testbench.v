module testbench;
  reg [3:0] a, b;
  wire [3:0] sum;
  initial begin
    #10;
    a = 4'b0010;
    b = 4'b1101;
    #10;
  end
endmodule
