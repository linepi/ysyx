module testbench();

reg a, b, c;
wire y;

f dut(a,b,c,y);
initial begin
    a = 0; b = 0; c = 0; #10;
end
endmodule