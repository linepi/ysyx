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
  prior_encoder #(8, 3) encoder83(.x(x), .en(en), .y(led));
  encode_seg enc_seg(.x({1'b0, led}), .y(seg));
endmodule

