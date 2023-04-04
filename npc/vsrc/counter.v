module counter(
  input clk,
  output reg Q0,
  output reg Q1,
  output reg Q2
);
  initial begin
    Q0 = 1;
    Q1 = 0;
    Q2 = 0;      
  end
  wire w1, w2, w3;
  dff dff_inst1(.clk(clk), .D(w1), .Q(Q0), ._Q(w1));
  dff dff_inst2(.clk(w1), .D(w2), .Q(Q1), ._Q(w2));
  dff dff_inst3(.clk(w2), .D(w3), .Q(Q2), ._Q(w3));
endmodule

module dff(
  input clk,
  input D,
  output reg Q,
  output reg _Q
);
  always @(posedge clk) begin
    Q <= D;
    _Q <= ~D; 
  end
endmodule