import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);

import "DPI-C" function void getpc(reg [63:0] *pc);

module PC (
  input clk
);
  wire [31:0] inst;
  reg [63:0] pc;
  initial begin
    pc = 64'h0000000080000000;
    getpc(&pc);
  end

  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = 0;
  wire [4:0] rd = inst[11:7];
  wire wen = 1;
  wire [63:0] imm = {{52{inst[31]}}, inst[31:20]}; // signed extend 
  wire [63:0] data1;
  wire [63:0] data2;
  wire [63:0] dataD;
  
  control i_control(clk, inst);

  register_file #(5, 64) r_rf(clk, rs1, rs2, rd, wen, dataD, data1, data2);
  alu #(64) a(.A(data1), .B(imm), .sel(4'd0), .res(dataD));
  alu #(64) a_pc(.A(pc), .B(64'd4), .sel(4'd0), .res(pc));

  wire [31:0] nothing;
  memory m_pc(.addr(pc), .wdata(64'd0), .wen(1'b0), .wmask(8'h0f), .rdata({nothing, inst}));
endmodule