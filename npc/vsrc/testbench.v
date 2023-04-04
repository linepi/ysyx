module testbench;
  reg clk, Q0, Q1, Q2;
  counter counter_ins(clk, Q0, Q1, Q2);
  
  reg [31:0] count_clk;
  always#10 clk = ~clk;

  always @(posedge clk) begin
    if (count_clk == 249999) begin
      count_clk <= 0;
    end 
    else begin
      count_clk <= count_clk + 1;
    end
  end
endmodule