%Daniel Charua - A01017419 - 25/11/18

%Funcion_palindroma
palindroma(Lista) :- palindroma(Lista, Lista, []).
palindroma([], Lista, Lista).
palindroma([H|T], Lista, R) :- palindroma(T, Lista, [H|R]).

%Funcion_permutation
%Se utilizo la funcion msort de Prolog
%obtenida de http://www.swi-prolog.org/pldoc/doc_for?object=msort/2
esPermutacion(Lista1, Lista2) :- msort(Lista1, Sorted), msort(Lista2, Sorted).

%Funcion_par
longitudPar([]).
longitudPar([_|T]) :- longitudInpar(T).
longitudInpar([_|T]) :- longitudPar(T).
