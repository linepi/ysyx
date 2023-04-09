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
  reg enable;
  initial enable = 1;

  keyboard keyboard_ins(clk, resetn, ps2_clk, ps2_data, code);
  encode_seg encode_seg_ins0(code[3:0], enable, seg0);
  encode_seg encode_seg_ins1(code[7:4], enable, seg1);
  always @(posedge clk) begin
    if(code == 8'hf0) begin
      enable = 0;
    end
  end
endmodule