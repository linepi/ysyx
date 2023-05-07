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
  initial set_gpr_ptr(rf);
  always @(posedge clk) begin
    if (wen) begin 
      rf[rd] <= dataD;
    end
  end
  wire [63:0] ground = 64'b0;
  // x0 register is always zero.
  always @(posedge clk) rf[0] <= ground;
  assign data1 = rf[rs1];
  assign data2 = rf[rs2];
endmodule