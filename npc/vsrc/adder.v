module adder
#(N)
(
    input [N-1 : 0] a,
    input [N-1 : 0] b,
    input cin,
    output [N-1 : 0] s,
    output cout
);
    assign {cout, s} = a + b + {3'b000, cin};
endmodule