module encode83(x, en, y);
  input [7:0] x;
  input en;
  output [2:0] y;
  integer i;

  always @ (x or en) begin
    if (en) begin
      for (i = 0; i < 8; i = i + 1) 
        if (x[i] == 1) y = i[2:0];
    end
    else y = 0;
  end 
endmodule

module encode_seg(x, y);
  input [3:0] x;
  output [6:0] y;
  always @ (x)
  begin
    case(x)
      0: y = 7'b0000001;
      1: y = 7'b0011000;
      2: y = 7'b1001000;
      3: y = 7'b1000010;
      default: y = 7'b0000000;
    endcase
  end
endmodule

module top(x, en, led, flag, seg);
  input [7:0] x;
  input en;
  output [2:0] led;
  output flag; // 0 only when x = 0 else 1
  output [6:0] seg;


  encode83 enc83(.x(x), .en(en), .y(led));
  encode_seg enc_seg(.x(x), .y(seg));
endmodule

