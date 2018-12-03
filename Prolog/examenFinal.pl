%Daniel Charua - Examen Final
%Promedio
promedio(Lista, R ):- suma( Lista, Suma ), length( Lista, Elementos), R is Suma / Elementos.
suma([], 0).
suma([H|T], Total):-suma(T, Numero1), Total is H + Numero1.

%Une
une([],Y,Y).
une([H|X],Y,[H|Z]):-une(X,Y,Z).
