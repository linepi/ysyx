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
  integer i;
  always @(posedge clk) begin
    if (wen) begin 
      rf[rd] <= dataD;
      $display("dataD %x write to rd %x", dataD, rd);
    end

    $display("Regs:");
    for (i = 0; i < (1 << ADDR_WIDTH); i = i + 2) begin
      $display("x%0d: %x, x%0d: %x", i, rf[i], i+1, rf[i+1]);
    end
  end
  assign rf[0] = 0;
  assign data1 = rf[rs1];
  assign data2 = rf[rs2];
endmodule