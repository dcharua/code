function [Y,E,M] = puntoFijo(X0, EPS, MAXIT)
    j=1;
    while(j<MAXIT)
        X= g(X0);
        if(abs(X-X0)<EPS)
            Y = X;
            E = 0;
            M = "Revisa el valor de y";
            return
        end
        j=j+1;
        X0=X;
    end
    Y=0;
    E=1;
    M="La funcion diverge en MAXIT pasos";
end
