%Daniel Charua     A01017419
function B = binario(D,N)
    %Se Inicializa el numero con 0.
	B = "0.";
	for(k=1:N)
        %Se multiplica por dos si es menor a uno se le agrega al string un 0
		D*=2;
		if(D<1)
            B = strcat (B,"0");
		else
            %si es mayor a 1 se le agrega al string un 1 y se resta un 1 del numero
            B = strcat (B,"1");
			D--;
		end
	end
end
