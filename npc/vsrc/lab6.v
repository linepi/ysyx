// 随机数发生器
module random_8(
    input clk,
    output reg [7:0] res
);
    reg newbit;
    initial begin
        res = 8'b10000101;
    end
    always@(posedge clk) begin
        newbit <= res[0] ^ res[3] ^ res[2] ^ res[4];
        res <= {newbit, res[7:1]};
    end
endmodule