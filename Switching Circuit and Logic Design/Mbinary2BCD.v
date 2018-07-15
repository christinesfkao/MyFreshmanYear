module Mbinary2BCD (a, h, t, u);
	input [6:0] a;
	output h;
	output [3:0] t;
	output [3:0] u;
	
	wire [3:0] k1;
	wire [3:0] k2;
	wire [3:0] k3;
	wire [3:0] k4;
	wire [3:0] k5;	
	
MAdd3 m0 ({1'b0, a[6:4]}, k1);
MAdd3 m1 ({k1[2:0], a[3]}, k2);
MAdd3 m2 ({k2[2:0], a[2]}, k3);
MAdd3 m3 ({1'b0, k1[3], k2[3], k3[3]}, k4);
MAdd3 m4 ({k3[2:0], a[1]}, k5);
 
assign h = k4[3];
assign t = {k4[2], k4[1], k4[0], k5[3]};
assign u = {k5[2], k5[1], k5[0], a[0]};
	
endmodule 
