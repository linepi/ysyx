module f(
    input a,
    input b,
    input c,
    output y
);

assign y = (~b & ~c) | (a & ~b);
endmodule
