module top(
  input a,
  input b,
  output f
);
  assign f = a ^ b + 1;
endmodule
