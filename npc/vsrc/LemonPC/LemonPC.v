`include "defines.v"

import "DPI-C" function void ebreak ();
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
import "DPI-C" function void npc_vmem_read(input longint raddr, output longint rdata);
import "DPI-C" function void npc_vmem_write(input longint waddr, input longint wdata, input byte wmask);

module PC(input clk, input rst, output reg [63:0] pc, output [31:0] inst);
  wire [31:0] nothing;
  // selects and flags
  wire ebreak_flag, pc_sel, alu_b_sel, 
    reg_wen, mem_wen, mem_ren,
    b_eq, b_lt, b_ltu; 
  wire [1:0] reg_w_sel, alu_a_sel;
  wire [2:0] imm_sel, mem_r_sel;
  wire [4:0] alu_sel;
  wire [7:0] mem_mask;

  wire [4:0] rs1 = inst[19:15];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rd = inst[11:7];
  wire [63:0] imm, reg1, reg2, regw;

  wire [63:0] _mem_data;
  mux_key #(7, 3, 64) mem_r_mux(mem_data, mem_r_sel, {
    `mem_r_sel_b, {{56{_mem_data[7]}}, _mem_data[7:0]},
    `mem_r_sel_h, {{48{_mem_data[15]}}, _mem_data[15:0]},
    `mem_r_sel_w, {{32{_mem_data[31]}}, _mem_data[31:0]},
    `mem_r_sel_d, _mem_data,
    `mem_r_sel_bu, {56'b0, _mem_data[7:0]},
    `mem_r_sel_hu, {48'b0, _mem_data[15:0]},
    `mem_r_sel_wu, {32'b0, _mem_data[31:0]}
  });
  wire [63:0] mem_data;

  wire [63:0] alu_a, alu_b, alu_res;
  mux_key #(3, 2, 64) alu_a_mux(alu_a, alu_a_sel, {
    `alu_a_sel_rs1, reg1,
    `alu_a_sel_pc, pc,
    `alu_a_sel_zero, 64'd0
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
    .inst(inst), .ebreak_flag(ebreak_flag), 
    .imm_sel(imm_sel), .pc_sel(pc_sel), .alu_sel(alu_sel),
    .alu_a_sel(alu_a_sel), .alu_b_sel(alu_b_sel),
    .reg_wen(reg_wen), .mem_wen(mem_wen), .mem_ren(mem_ren), .mem_mask(mem_mask),
    .reg_w_sel(reg_w_sel), .mem_r_sel(mem_r_sel),
    .b_eq(b_eq), .b_lt(b_lt), .b_ltu(b_ltu)
  );
  register_file #(5, 64) r_rf(clk, rs1, rs2, rd, reg_wen, regw, reg1, reg2);

  alu #(64) a(.A(alu_a), .B(alu_b), .sel(alu_sel), .res(alu_res));
  branch_comp i_bc(reg1, reg2, b_eq, b_lt, b_ltu);
  imm_gen i_imm_gen(inst, imm_sel, imm);
  memory d_mem(.addr(alu_res), .wdata(reg2), .wen(mem_wen), .ren(mem_ren), .wmask(mem_mask), .rdata(_mem_data));

  // about pc and instruction 
  wire [63:0] snpc, dnpc;
  memory i_mem(.addr(pc), .wdata(64'd0), .wen(`false), .ren(~rst), .wmask(`mem_mask_read), .rdata({nothing, inst}));

  assign snpc = pc + 4;
  mux_key #(2, 1, 64) pc_mux(dnpc, pc_sel, {
    `pc_sel_snpc, snpc, 
    `pc_sel_alu, alu_res
  });
  always @(posedge clk) begin
    if (rst) begin 
      pc <= `PC_INIT;
    end else begin 
      pc <= dnpc;
    end
    if (ebreak_flag) ebreak();
  end
endmodule