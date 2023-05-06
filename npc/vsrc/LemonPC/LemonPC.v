import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);
    
module PC (
  input clk,
  output reg [31:0] inst,
  output reg [63:0] pc
);
  // wire [31:0] inst;
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

  wire [31:0] nothing;
  memory i_memory(.addr(pc), .wdata(64'd0), .wen(1'b0), .wmask(8'h0f), .rdata({nothing, inst}));

  always @(posedge clk) begin
    pc = pc + 4;
  end
endmodule