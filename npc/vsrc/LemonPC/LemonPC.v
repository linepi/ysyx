module PC (
    input [31:0] inst,
    output [63:0] pc
);
    assign pc = {32'b0, 32'h80000000};
endmodule