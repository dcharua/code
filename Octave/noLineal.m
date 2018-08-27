function [x,E, i] = noLineal(X0, EPS, MAXIT, metodo)
    if (metodo == 0)
        k = 1;
        %Loop para verificar que no pase las itereciones maximas
        while(k<MAXIT)
            % Se aplica la formaula para calcular el valor de X
            X = X0 - f(X0)/df(X0);
            % Si el error es menor al EPS regresar el resultado
            if(abs(X-X0)<EPS)
                x = X;
                E = 0;
                i = k;
                return;
            end
            %Se aumenta el contador y se asigna la X1 a X0
            k++;
            X0 = X;
        end
        % si sale del loop de Maxit el valor no converge en los paseos, regresa error
        x = "El metodo no converge";
        E = 1;
        i = MAXIT;
        return;

    elseif(metodo == 1)
        % se obtiene el valor de X1 y X2
        X1 = X0(1);
        X2 = X0(2);
        k = 1;
        %Loop para verificar que no pase las itereciones maximas
        while(k<MAXIT)
             %Se aplica la formaula para calcular el valor de X
            X = (X2 - (f(X2)*(X2-X1))/ (f(X2)-f(X1)));
            % Si el error es menor al EPS regresar el resultado
            if(abs((X-X2))<EPS)
                x = X;
                E = 0;
                i = k;
                return;
            end
            %Se aumenta el contador y mueven los valores iniciales a X y X2
            k++;
            X1 = X2;
            X2 = X;
        end
        % si sale del loop de Maxit el valor no converge en los paseos, regresa error
        x = "El metodo no converge";
        E = 1;
        i = MAXIT;
        return;

    elseif(metodo == 2)
        % se obtiene el valor de X1 y X2
        k = 0;
        X1 = X0(1);
        X2 = X0(2);
        %Loop para verificar que no pase las itereciones maximas
        while(k<MAXIT)
            %Se aplica la formaula para calcular el valor de X
            X = (X1 + X2)/2;
            % se checa que la si la multiplicacion de la funcion evaluada en X1 y x2 es negativa (hay cambio se signos). si no los valores iniciales no son validos
            if((f(X1)* f(X2)) < 0)
                E = abs((X1-X2)/2);
                % si la multipicaion  de Xm y X1 es postiva se cambia X1 por X.
                if((f(X)* f(X1)) > 0)
                    X1 = X;
                    % si es negativa se cambia X2 por X
                else
                    X2 = X;
                end
                % si no hay cambio de signos, los valores iniciales no sirven, se regresa error
            else
                x = "Los valores iniciales son invalidos";
                E = 1;
                i = k;
                return;
            end
            % se aumenta el contador y se verifica si el error es menor al EPS, de ser el caso se regresa el valor
            k++;
            if(E<=EPS)
                x = X;
                E = 0;
                i = k;
                return;
            end
        end
        % si ya paso el Maxit, se regresa el error
    x = "El metodo no converge en elnumero de pasos";
    E = 1;
    i = MAXIT;
    end
end
