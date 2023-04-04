// 随机数发生器
module random_8(
    input clk,
    output reg [7:0] res
);
    always@(posedge clk) begin
        assign newbit <= res[0] ^ res[1] ^ res[4];
        res <= {newbit, res[7:1]};
    end
endmodule