module alu
#(N)
(
    input [N-1:0] A, B,  // ALU Inputs                 
    input [3:0] select,// ALU Selection
    output [N-1:0] res, // ALU Output
);
    always @(*)
    begin
        case(select)
            4'b0000: // Addition
            res = A + B ; 
            4'b0001: // Subtraction
            res = A - B ;
            4'b0010: // Multiplication
            res = A * B;
            4'b0011: // Division
            res = A / B;
            4'b0110: //  Logical and 
            res = A & B;
            4'b0111: //  Logical or
            res = A | B;
            4'b1000: //  Logical xor 
            res = A ^ B;
            4'b1001: // Greater comparison
            res = (A < B)? 8'd1 : 8'd0 ;
            4'b1010: // Equal comparison   
            res = (A == B) ? 8'd1 : 8'd0 ;
            default: res = 0; 
        endcase
    end
endmodule