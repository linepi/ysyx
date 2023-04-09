module encode_seg(x, enable, y);
  input [3:0] x;
  input enable;
  output reg [6:0] y;
  always @ (x or enable)
  begin
    if(enable) begin
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
    end else begin
      y = 7'b1111111;
    end
  end
endmodule