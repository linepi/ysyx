module top(x, y, seg1, seg0);
  input [3:0] x;
  input [3:0] y;
  output reg [6:0] seg1;
  output reg [6:0] seg0;

  wire [3:0] s;
  wire cout;
  assign {cout, s} = x + y;
  encode_seg enc1(.x(s), .y(seg0));
  encode_seg enc2(.x({3'b000, cout}), .y(seg1));
endmodule

