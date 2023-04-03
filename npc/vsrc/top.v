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
      0: y = 7'b1000000;
      1: y = 7'b1111001;
      2: y = 7'b0100100;
      3: y = 7'b0110000;
      4: y = 7'b0011001;
      5: y = 7'b0010010;
      6: y = 7'b0000010;
      7: y = 7'b1111000;
      8: y = 7'b0000000;
      9: y = 7'b0010000;
      10: y = 7'b0001000;
      11: y = 7'b0000011;
      12: y = 7'b1000110;
      13: y = 7'b0100001;
      14: y = 7'b0000110;
      15: y = 7'b0001110;
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

