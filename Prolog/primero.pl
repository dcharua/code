liga(fortran, algol60).
liga(algol60, cpl).
liga(cpl, bcpl).
liga(bcpl, c).
liga(c, cmasmas).
liga(algol60, simula67).
liga(simula67, cmasmas).
liga(simula67, smalltalk80).


%probando
liga(fortran, algol60), liga(algol60, simula 67).
%true.


liga(cpl, L), liga(L, c).
L = bcpl

liga(fortran, L), liga(L, T).
L = algol60
T = cpl ;
L = algol60
T = simula67

// suma
X is 4+5.

%Recursion para encontrar rutas
ruta(L,L).
ruta(L,X):-liga(L,F),ruta(F,X).

%Existen dos lenguajes L y M que se liguen al mismo lenguaje N

%primer intento
%liga(L,N),liga(M,N).

%correjido
%liga(L,N),liga(M,N),not(L=M).

%Factorial
fact(0,1).
fact(N,F):- N>0, N1 is N-1, fact(N1,F1),F is N*F1.


%agrega
agrega([],Y,Y).
agrega([H|X],Y,[H|Z]):-agrega(X,Y,Z)

%potenica
potencia(A,1,A).
potencia(A,B,R):-B>1, B1 is B-1, potencia(A,B1,R1), R is A*R1.

longitud([], 0).
longitud([_|T], R):- longitud(T,R1), R is R1 + 1.

miembro(A, [A|_]):- !.
miembro(A, [_|T]):- miembro(A,T).
