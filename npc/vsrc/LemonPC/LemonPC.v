import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);


module PC(input clk, output reg [63:0] pc, output [31:0] inst);
  wire [63:0] npc;
  wire [31:0] nothing;
  // selects 
  wire [2:0] imm_sel;

  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rd = inst[11:7];
  wire [63:0] imm; 
  wire wen = 1;
  wire ebreak_flag;
  reg rst = 1;
  wire [63:0] data1;
  wire [63:0] data2;
  wire [63:0] dataD;
  
  
  control i_control(.clk(clk), .inst(inst), .ebreak_flag(ebreak_flag), .imm_sel(imm_sel));
  register_file #(5, 64) r_rf(clk, rs1, rs2, rd, wen, dataD, data1, data2);

  alu #(64) a(.A(data1), .B(imm), .sel(4'd0), .res(dataD));
  alu #(64) a_pc(.A(pc), .B(64'd4), .sel(4'd0), .res(npc));
  memory m_pc(.addr(pc), .wdata(64'd0), .wen(1'b0), .wmask(8'h0f), .rdata({nothing, inst}));

  imm_gen i_imm_gen(inst, imm_sel, imm);

  initial begin
    pc = 64'h0000000080000000;
  end
  always @(posedge clk) begin
    pc <= npc;
    if (ebreak_flag) ebreak();
  end
endmodule