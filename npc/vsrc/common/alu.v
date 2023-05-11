module alu #(N) (
  input [N-1:0] A, 
  input [N-1:0] B,
  input [3:0] sel,  
  output reg [N-1:0] res   
);
  always @(*) begin
    case(sel)
      4'd0: res = A + B; 
      4'd1: res = A - B;
      4'd2: res = A * B;
      4'd3: res = A / B;
      4'd4: res = A & B;
      4'd5: res = A | B;
      4'd6: res = A ^ B;
      4'd7: res = (A >= B) ? 64'd1 : 64'd0;
      4'd8: res = (A < B) ? 64'd1 : 64'd0;
      4'd9: res = (A == B) ? 64'd1 : 64'd0;
      4'd10: res = (A != B) ? 64'd1 : 64'd0;
      4'd11: res = A << B;
      4'd12: res = A >> B;
      4'd13: res = A >>> B;
      default: res = 0; 
    endcase
  end
endmodule