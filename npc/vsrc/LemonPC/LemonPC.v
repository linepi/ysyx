import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);
    
module PC (
  input clk,
  input [31:0] inst,
  output reg [63:0] pc
);
  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = 0;
  wire [4:0] rd = inst[11:7];
  wire wen = 1;
  wire [63:0] imm = {{52{inst[31]}}, inst[31:20]}; // signed extend 
  wire [63:0] data1;
  wire [63:0] data2;
  wire [63:0] dataD;
  
  control i_control(inst);

  register_file #(5, 64) i_rf(clk, rs1, rs2, rd, wen, dataD, data1, data2);
  alu #(64) i_alu(.A(data1), .B(imm), .sel(4'd0), .res(dataD));

  always @(posedge clk) begin
    pc = pc + 4;
  end

  wire [63:0] rdata;
  wire [63:0] raddr;
  wire [63:0] waddr;
  wire [63:0] wdata;
  wire [7:0] wmask;
  always @(*) begin
    npc_vmem_read(raddr, rdata);
    npc_vmem_write(waddr, wdata, wmask);
  end
endmodule