module top(
  input clk,
  output reg Q0,
  output reg Q1,
  output reg Q2
);
  counter counter_ins(.clk(clk), .Q0(Q0), .Q1(Q1), .Q2(Q2));
endmodule
