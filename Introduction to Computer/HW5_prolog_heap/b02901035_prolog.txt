sroot(_, 1, 1).

sroot(X, M, SX):-
    X > 0,
    M > 0,
    M1 is M-1,
    sroot(X, M1, SX1),
    SX is (SX1*SX1 + X)/(2*SX1).