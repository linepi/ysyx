module PC (
    input clk,
    input [31:0] inst,
    output reg [63:0] regs[32],
    output reg pc
);
    initial begin
        assign pc = {32'd0, 32'h80000000};
    end

    register_file i0(.clk(clk), )

    always @(posedge clk) begin

    end
endmodule