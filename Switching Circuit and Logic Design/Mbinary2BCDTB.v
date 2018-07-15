module Mbinary2BCDTB;
  reg [6:0] a;
  wire hunds;
  wire [3:0] tens;
  wire [3:0] units;
  Mbinary2BCD b2bcd1 (.a(a),.h(hunds),.t(tens),.u(units));
  initial #256 $finish;
  initial begin
    $dumpfile("b2bcd.fsdb");
    $dumpvars();
    a = 7'h00;
    #32 a = 7'h12;
    #32 a = 7'h29;
    #32 a = 7'h30;
    #32 a = 7'h41;
    #32 a = 7'h50;
    #32 a = 7'h63;
    #32 a = 7'h75;
   end
endmodule
