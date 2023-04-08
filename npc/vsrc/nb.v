module top(
  input clk,
  input ps2_clk,
  input ps2_data,
  input resetn
);
  keyboard keyboard_ins(clk, resetn, ps2_clk, ps2_data);
endmodule