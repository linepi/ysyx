module prior_encoder
#(parameter INN = 4, OUTN = 2)
(
  input [INN-1 : 0] x;
  input en;
  output reg [OUTN-1 : 0] y;
);
  integer i;

  always @(x or en) begin
    y = 0;
    if (en) begin
      for (i = 0; i < INN; i = i + 1) 
        if (x[i] == 1) y = i[OUTN : 0];
    end
    else y = 0;
  end 
endmodule