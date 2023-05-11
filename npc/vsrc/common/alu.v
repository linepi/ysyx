module alu #(N) (
  input [N-1:0] A, 
  input [N-1:0] B,
  input [4:0] sel,  
  output reg [N-1:0] res   
);
  always @(*) begin
    case(sel)
      4'd0: res = A + B; 
      4'd1: res = A - B;
      4'd2: res = A * B;
      4'd3: res = B == 64'd0 ? `ALL_ONE : $signed(A) / $signed(B);
      4'd4: res = B == 64'd0 ? `ALL_ONE : A / B;
      4'd5: res = B == 64'd0 ? A : $signed(A) % $signed(B);
      4'd6: res = B == 64'd0 ? A : A % B;
      4'd7: res = A & B;
      4'd8: res = A | B;
      4'd9: res = A ^ B;
      4'd10: res = (A >= B) ? 64'd1 : 64'd0;
      4'd11: res = (A < B) ? 64'd1 : 64'd0;
      4'd12: res = (A == B) ? 64'd1 : 64'd0;
      4'd13: res = (A != B) ? 64'd1 : 64'd0;
      4'd14: res = ($signed(A) >= $signed(B)) ? 64'd1 : 64'd0;
      4'd15: res = ($signed(A) < $signed(B)) ? 64'd1 : 64'd0;
      4'd16: res = A << B;
      4'd17: res = A >> B;
      4'd18: res = A >>> B;
      4'd19: begin 
        reg [31:0] tmp = A[31:0] + B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd20: begin
        reg [31:0] tmp = A[31:0] - B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd21: begin
        reg [31:0] tmp = A[31:0] << B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd22: begin
        reg [31:0] tmp = A[31:0] >> B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd23: begin
        reg [31:0] tmp = A[31:0] >>> B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd24: begin
        reg [31:0] tmp = A[31:0] * B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd25: begin
        reg [31:0] tmp = B == 0 ? -1 : $signed(A[31:0]) / $signed(B[31:0]);
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd26: begin
        reg [31:0] tmp = B == 0 ? -1 : A[31:0] / B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd27: begin
        reg [31:0] tmp = B == 0 ? A[31:0] : $signed(A[31:0]) % $signed(B[31:0]);
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      4'd28: begin
        reg [31:0] tmp = B == 0 ? A[31:0] : A[31:0] % B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      default: res = 0; 
    endcase
  end
endmodule