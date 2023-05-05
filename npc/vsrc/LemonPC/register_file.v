module register_file #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [ADDR_WIDTH-1:0] rs1,
  input [ADDR_WIDTH-1:0] rs2,
  input [ADDR_WIDTH-1:0] rd,
  input wen,
  input [DATA_WIDTH-1:0] dataD,
  output [DATA_WIDTH-1:0] data1,
  output [DATA_WIDTH-1:0] data2
);
  reg [DATA_WIDTH-1:0] rf [(1<<ADDR_WIDTH)-1 : 0];
  always @(posedge clk) begin
    if (wen) rf[rd] <= dataD;
  end
  // x0 is always zero.
  assign rf[0] = 0;
  assign data1 = rf[rs1];
  assign data2 = rf[rs2];
endmodule