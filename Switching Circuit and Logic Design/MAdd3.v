module MAdd3 (x, y);
input [3:0] x;
output [3:0] y;

wire [2:0] t3;
wire [1:0] t2;
wire [2:0] t1;
wire [2:0] t0;
wire [3:0] xp;

//set up inverters
not n3 (xp[3], x[3]);
not n2 (xp[2], x[2]);
not n1 (xp[1], x[1]);
not n0 (xp[0], x[0]);
   
and a31 (t3[1], x[2], x[0]);   
and a30 (t3[0], x[2], x[1]);   
or o3 (y[3], x[3], t3[1], t3[0]);   
// y[3] completed

and a21 (t2[1], x[2], xp[1], xp[0]);
and a20 (t2[0], x[3], x[0]);
or o2 (y[2], t2[1], t2[0]);
// y[2] completed

and a12 (t1[2], xp[2], x[1]);
and a11 (t1[1], x[3], xp[0]);
and a10 (t1[0], x[1], x[0]);
or o1 (y[1], t1[2], t1[1], t1[0]);
// y[1] completed

and a02 (t0[2], xp[3], xp[2], x[0]);
and a01 (t0[1], x[2], x[1], xp[0]);
and a00 (t0[0], x[3], xp[0]);
or o0 (y[0], t0[2], t0[1], t0[0]);
// y[0] completed   

endmodule 
