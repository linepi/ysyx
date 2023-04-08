// 使用随机数发生器，让8-bit随机数显示在两个7段数码管上
module top(
  input clk,
  input ps2_clk,
  input ps2_data,
  input resetn
);
  ps2_keyboard ps2_keyboard_ins(clk, resetn, ps2_clk, ps2_data);
endmodule