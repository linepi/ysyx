// 使用随机数发生器，让8-bit随机数显示在两个7段数码管上
module top(
  input clk,
  output reg [6:0] seg1,
  output reg [6:0] seg0
);
  wire [7:0] random; 
  random_8 random_8_ins(.clk(clk), .res(random));
  encode_seg enc_ins1(.x(random[7:4]), .y(seg1));
  encode_seg enc_ins2(.x(random[3:0]), .y(seg0));
endmodule