%Daniel Charua     A01017419
function A = perimetro(M)
    A=0;
    %Se lee el numero de columnas
	[F,C]=size(M);
    %Se hace un for hasta la peniltima columna
	for(k=1:C-1)
        %Se le aplica la formula matematica y se le asigana a A
        L=sqrt( ((M(1,k)-M(1,k+1))^2) + ((M(2,k)-M(2,k+1))^2));
		A+=L;
	endfor
    %Se le aplica la formula matematica al primer y el ultimo elemento y se le suma a A
    L=sqrt( ((M(1,C)-M(1,1))^2) + ((M(2,C)-M(2,1))^2));
    A+=L;
end
