module MAdd3TB;
  reg [3:0] x;
  wire [3:0] y;
  
  MAdd3 add31 (.x(x),.y(y));

  initial #256 $finish;
  
  initial begin
    $dumpfile("MAdd3.fsdb");
    $dumpvars();
    x=4'h0; #16 x = 4'h1; #16 x = 4'h2; #16 x = 4'h3;
    #16 x = 4'h4; #16 x = 4'h5; #16 x = 4'h6; #16 x = 4'h7;
    #16 x = 4'h8; #16 x = 4'h9; #16 x = 4'ha; #16 x = 4'hb;
    #16 x = 4'hc; #16 x = 4'hd; #16 x = 4'he; #16 x = 4'hf;
  end
  
endmodule
