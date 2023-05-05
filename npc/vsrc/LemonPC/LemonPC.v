module PC (
    input clk,
    input [31:0] inst,
    output reg [63:0] regs[32],
    output reg [63:0] pc
);
    always @(posedge clk) begin
        pc = pc + 4;       
    end
endmodule