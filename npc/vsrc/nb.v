module nb(
  input clk,
  input ps2_clk,
  input ps2_data,
  input resetn,
  output reg [6:0] seg0,
  output reg [6:0] seg1
  output reg [6:0] seg2;
  output reg [6:0] seg3;
  output reg [6:0] seg4;
  output reg [6:0] seg5;
  output reg [6:0] seg6;
  output reg [6:0] seg7;
);
  wire [7:0] code;
  reg enable;
  initial begin 
    seg0[7] = 1;
    seg1[7] = 1;
    seg2[7] = 1;
    seg3[7] = 1;
    seg4[7] = 8'b11000000;
    seg5 = 8'b11111111;
    seg6 = 8'b11111111;
    seg7 = 8'b11111111;
    enable = 1;
  end

  keyboard keyboard_ins(clk, resetn, ps2_clk, ps2_data, code);
  encode_seg encode_seg_ins0(code[3:0], enable, seg0);
  encode_seg encode_seg_ins1(code[7:4], enable, seg1);
  always @(posedge clk) begin
    if(code == 8'hf0) begin
      enable = 0;
    end
  end
endmodule