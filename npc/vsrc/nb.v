module nb(
  input clk,
  input ps2_clk,
  input ps2_data,
  input resetn,
  output reg [6:0] seg0,
  output reg [6:0] seg1
  // output reg [6:0] seg2;
  // output reg [6:0] seg3;
);
  wire [7:0] code;
  keyboard keyboard_ins(clk, resetn, ps2_clk, ps2_data, code);
  encode_seg encode_seg_ins0(code[3:0], seg0);
  encode_seg encode_seg_ins1(code[7:4], seg1);
endmodule