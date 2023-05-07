module ver (
    input a,
    input b,
    output c
);
    assign c = a & b;
	always @(*) $display("h");
endmodule
