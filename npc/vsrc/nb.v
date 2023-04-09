module nb(
  input clk,
  input ps2_clk,
  input ps2_data,
  input resetn,
  output reg [7:0] seg0,
  output reg [7:0] seg1,
  output reg [7:0] seg2,
  output reg [7:0] seg3,
  output reg [7:0] seg4,
  output reg [7:0] seg5,
  output reg [7:0] seg6,
  output reg [7:0] seg7
);
  wire [7:0] code;
  wire [7:0] ascii;
  reg [15:0] cnt;
  reg enable;
  initial begin 
    seg0[7] = 1;
    seg1[7] = 1;
    seg2[7] = 1;
    seg3[7] = 1;
    cnt = 0;
    seg4[7] = 1;
    seg5[7] = 1;
    seg6[7] = 1;
    seg7[7] = 1;
    enable = 1;
  end

  keyboard keyboard_ins(clk, ~resetn, ps2_clk, ps2_data, enable, code);
  ascii_map ascii_map_ins(code, ascii);
  encode_seg encode_seg_ins0(code[3:0], enable, seg0[6:0]);
  encode_seg encode_seg_ins1(code[7:4], enable, seg1[6:0]);
  encode_seg encode_seg_ins2(ascii[3:0], enable, seg2[6:0]);
  encode_seg encode_seg_ins3(ascii[7:4], enable, seg3[6:0]);

  encode_seg encode_seg_ins4(cnt[3:0], 1, seg4[6:0]);
  encode_seg encode_seg_ins5(cnt[7:4], 1, seg5[6:0]);
  encode_seg encode_seg_ins6(cnt[11:8], 1, seg6[6:0]);
  encode_seg encode_seg_ins7(cnt[15:12], 1, seg7[6:0]);
  always @(posedge enable) begin
    cnt <= cnt + 1; 
  end
endmodule

// number's ascii(partly)
module ascii_map (
  input [7:0] code,
  output reg [7:0] ascii
);
  always @(code)
  begin
    case (code)
      8'h16: ascii = 8'h31; 
      8'h1e: ascii = 8'h32; 
      8'h26: ascii = 8'h33; 
      8'h25: ascii = 8'h34; 
      8'h2e: ascii = 8'h35; 
      8'h36: ascii = 8'h36; 
      8'h3d: ascii = 8'h37; 
      8'h3e: ascii = 8'h38; 
      8'h46: ascii = 8'h39; 
      8'h45: ascii = 8'h30; 
      default: ascii = 8'hff;
    endcase 
  end
endmodule