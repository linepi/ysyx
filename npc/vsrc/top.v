module top(x1, x2, x3, x4, s, y);
  input [1:0] x1;
  input [1:0] x2;
  input [1:0] x3;
  input [1:0] x4;
  input [1:0] s;
  output reg [1:0] y;
  always @ (s or x1 or x2 or x3 or x4)
    case (s)
      2'b00: y = x1;
      2'b01: y = x2;
      2'b10: y = x3;
      2'b11: y = x4;
      default: y = 2'b00;
    endcase
endmodule