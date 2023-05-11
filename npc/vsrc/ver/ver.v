import "DPI-C" function void set_ptr(chandle pc, int flag);

module ver (
    input a,
    input b,
    output c
);
    assign c = a & b;
	always @(*) $display("h");
endmodule
