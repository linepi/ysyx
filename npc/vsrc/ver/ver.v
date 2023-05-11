import "DPI-C" function void set_ptr(chandle pc, int flag);

module ver (
    input a,
    input b,
    output c
);
    initial begin
        #10;
        chandle c_ptr = $sformatf("%p", c);
        set_ptr(c_ptr, 1);
    end
    assign c = a & b;
	always @(*) $display("h");
endmodule
