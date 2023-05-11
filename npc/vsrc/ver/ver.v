import "DPI-C" function void set_ptr(chandle pc, int flag);

module ver (
    input a,
    input b,
    output c
);
    initial begin
        #10
    end
    assign c = a & b;
	always @(*) $display("h");
endmodule
