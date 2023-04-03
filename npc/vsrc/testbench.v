module testbench;
  reg [3:0] a, b;
  wire [3:0] sum;
  adder add_inst (.a(a), .b(b), .sum(sum));

  initial begin
    #10;
    a = 4'b0010;
    b = 4'b1101;
    #10;
  end

endmodule

module adder(
  input [3:0] a,
  input [3:0] b,
  output reg [3:0] sum
);

  always @(a, b) begin
    sum = a + b;
    $display("The sum of %d and %d is %d", a, b, sum);
  end

endmodule
