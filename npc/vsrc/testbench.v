module testbench;
  reg clk, Q0, Q1, Q2;
  counter counter_ins(clk, Q0, Q1, Q2);
  
  always#10 begin 
    clk = ~clk;
  end
  // always @(posedge clk) begin
  //   $display("%d %d %d", Q2, Q1, Q0);
  // end
  initial begin
    $timeformat(-9, 0, "ns");
    $monitor("%t: Message", $stime);
    #100 $finish;
  end
endmodule