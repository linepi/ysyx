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
    if (wen) begin 
      rf[rd] <= dataD;
    end
  end
  assign rf[0] = 0;
  assign data1 = rf[rs1];
  assign data2 = rf[rs2];

  reg [DATA_WIDTH-1:0] rf_debug [(1<<ADDR_WIDTH)-1 : 0];
  reg [DATA_WIDTH-1:0] rf_debug_last [(1<<ADDR_WIDTH)-1 : 0];
  integer i;
  always @(posedge clk) begin
    if (wen) begin 
      rf_debug[rd] = dataD;
      for (i = 0; i < (1 << ADDR_WIDTH); i++) begin
        if (rf_debug_last[i] != rf_debug[i])
          $display("x%0d changed, from %x to %x", i, rf_debug_last[i], rf_debug[i]);
      end
      rf_debug_last[rd] = dataD;
    end
  end
endmodule