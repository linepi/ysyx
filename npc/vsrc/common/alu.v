module alu #(N) (
  input [N-1:0] A, 
  input [N-1:0] B,
  input [4:0] sel,  
  output reg [N-1:0] res   
);
  reg [31:0] tmp;
  always @(*) begin
    case(sel)
      5'd0: res = A + B; 
      5'd1: res = A - B;
      5'd2: res = A * B;
      5'd3: res = B == 64'd0 ? -1 : $signed(A) / $signed(B);
      5'd4: res = B == 64'd0 ? -1 : A / B;
      5'd5: res = B == 64'd0 ? A : $signed(A) % $signed(B);
      5'd6: res = B == 64'd0 ? A : A % B;
      5'd7: res = A & B;
      5'd8: res = A | B;
      5'd9: res = A ^ B;
      5'd10: res = (A >= B) ? 64'd1 : 64'd0;
      5'd11: res = (A < B) ? 64'd1 : 64'd0;
      5'd12: res = (A == B) ? 64'd1 : 64'd0;
      5'd13: res = (A != B) ? 64'd1 : 64'd0;
      5'd14: res = ($signed(A) >= $signed(B)) ? 64'd1 : 64'd0;
      5'd15: res = ($signed(A) < $signed(B)) ? 64'd1 : 64'd0;
      5'd16: res = A << B;
      5'd17: res = A >> B;
      5'd18: res = A >>> B;
      5'd19: begin 
        tmp = A[31:0] + B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd20: begin
        tmp = A[31:0] - B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd21: begin
        tmp = A[31:0] << B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd22: begin
        tmp = A[31:0] >> B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd23: begin
        tmp = A[31:0] >>> B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd24: begin
        tmp = A[31:0] * B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd25: begin
        tmp = B == 0 ? -1 : $signed(A[31:0]) / $signed(B[31:0]);
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd26: begin
        tmp = B == 0 ? -1 : A[31:0] / B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd27: begin
        tmp = B == 0 ? A[31:0] : $signed(A[31:0]) % $signed(B[31:0]);
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      5'd28: begin
        tmp = B == 0 ? A[31:0] : A[31:0] % B[31:0];
        res = {{32{tmp[31]}}, tmp[31:0]};
      end
      default: begin
        tmp = 32'd0;
        res = 64'd0; 
      end
    endcase
  end
endmodule