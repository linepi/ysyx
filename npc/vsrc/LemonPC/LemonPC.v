`include "defines.v"

import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);


module PC(input clk, output reg [63:0] pc, output [31:0] inst);
  wire [31:0] nothing;
  // selects and flags
  wire ebreak_flag, pc_sel, alu_a_sel, alu_b_sel, 
    reg_wen, mem_wen; 
  wire [1:0] reg_w_sel;
  wire [2:0] imm_sel;
  wire [3:0] alu_sel;
  wire [7:0] mem_mask;

  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rd = inst[11:7];
  wire [63:0] imm, reg1, reg2, regw;

  wire [63:0] mem_data;

  wire [63:0] alu_a, alu_b, alu_res;
  mux_key #(2, 1, 64) alu_a_mux(alu_a, alu_a_sel, {
    `alu_a_sel_rs1, reg1,
    `alu_a_sel_pc, pc
  });
  mux_key #(2, 1, 64) alu_b_mux(alu_b, alu_b_sel, {
    `alu_b_sel_rs2, reg2,
    `alu_b_sel_imm, imm
  });
  mux_key #(3, 2, 64) reg_w_mux(regw, reg_w_sel, {
    `reg_w_sel_alu, alu_res,
    `reg_w_sel_mem, mem_data,
    `reg_w_sel_pc, snpc
  });
  
  control i_control(
    .clk(clk), .inst(inst), .ebreak_flag(ebreak_flag), 
    .imm_sel(imm_sel), .pc_sel(pc_sel), .alu_sel(alu_sel),
    .alu_a_sel(alu_a_sel), .alu_b_sel(alu_b_sel),
    .reg_wen(reg_wen), .mem_wen(mem_wen), .mem_mask(mem_mask),
    .reg_w_sel(reg_w_sel)
  );
  register_file #(5, 64) r_rf(clk, rs1, rs2, rd, reg_wen, regw, reg1, reg2);

  alu #(64) a(.A(alu_a), .B(alu_b), .sel(alu_sel), .res(alu_res));
  imm_gen i_imm_gen(inst, imm_sel, imm);
  memory m_mem(.addr(alu_res), .wdata(reg2), .wen(mem_wen), .wmask(mem_mask), .rdata(mem_data));

  // about pc and instruction 
  wire [63:0] snpc, dnpc;
  memory m_inst(.addr(pc), .wdata(64'd0), .wen(1'b0), .wmask(`mem_mask_read), .rdata({nothing, inst}));
  alu #(64) a_snpc(.A(pc), .B(64'd4), .sel(4'd0), .res(snpc));
  mux_key_with_default #(2, 1, 64) pc_mux(dnpc, pc_sel, `PC_INIT, {
    `pc_sel_snpc, snpc, 
    `pc_sel_alu, alu_res
  });
  always @(posedge clk) begin
    pc <= dnpc;
    if (ebreak_flag) ebreak();
  end
  initial begin
    pc = `PC_INIT;
  end
endmodule