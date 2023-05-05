module PC (
  input clk,
  input [31:0] inst,
  output reg [63:0] pc
);
  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = 0;
  wire [4:0] rd = inst[11:7];
  // signed extend
  wire [63:0] imm = {{52{inst[31]}}, inst[31:20]};
  wire [63:0] data1;
  wire [63:0] data2;
  wire [63:0] dataD;

  register_file #(5, 64) i_rf(.clk(clk),.rs1(rs1),.rs2(rs2),.rd(rd),.wen(1),.dataD(dataD),.data1(data1),.data2(data2));
  alu #(64) i_alu(.A(data1), .B(imm), .sel(4'd0), .res(dataD));
  always @(posedge clk) begin
    pc = pc + 4;
  end
endmodule