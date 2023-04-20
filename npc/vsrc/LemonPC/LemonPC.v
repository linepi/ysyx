module PC (
    input [31:0] inst,
    output reg [63:0] pc
);
    initial begin
        assign pc = {32'd0, 32'h80000000};
    end
    assign pc = {32'd0, 32'h80000001};
endmodule