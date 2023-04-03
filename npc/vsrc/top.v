module encode83(x, en, y);
  input [7:0] x;
  input en;
  output reg [2:0] y;
  integer i;

  always @(x or en) begin
    y = 0;
    if (en) begin
      for (i = 0; i < 8; i = i + 1) 
        if (x[i] == 1) y = i[2:0];
    end
    else y = 0;
  end 
endmodule

module encode_seg(x, y);
  input [3:0] x;
  output reg [6:0] y;
  always @ (x)
  begin
    case(x)
      0: y = 7'b0111111;
      1: y = 7'b0000110;
      2: y = 7'b1011011;
      3: y = 7'b1001111;
      4: y = 7'b1100110;
      5: y = 7'b1101101;
      6: y = 7'b1111101;
      7: y = 7'b0000111;
      8: y = 7'b1111111;
      9: y = 7'b1101111;
      1'hA: y = 7'b1110111;
      1'hB: y = 7'b1111100;
      1'hC: y = 7'b0111001;
      1'hD: y = 7'b1011110;
      1'hE: y = 7'b1111001;
      1'hF: y = 7'b1110001;
    endcase
  end
endmodule

module top(x, en, led, flag, seg);
  input [7:0] x;
  input en;
  output reg [2:0] led;
  output reg flag; // 0 only when x = 0 else 1
  output reg [6:0] seg;

  always @(*) begin
    if (x != 0 && en) flag = 1;
    else flag = 0;
  end
  encode83 enc83(.x(x), .en(en), .y(led));
  encode_seg enc_seg(.x({1'b0, led}), .y(seg));
endmodule

