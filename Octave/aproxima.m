function [A,E] = aproxima(X, Y, N, O, P)
    %verifica que los vectores tengan la misma longitud
    if length(X) != length(Y)
        A = 0;
        E = "Error los vertices nos son equivalemtes";
        return;
    end

    %verifica que existan al menos N+1 puntos, es decir al menos un punto mas que el grado.
    if N >= length(X)
        A = 0;
        E = "No hay suficientes puntos";
        return;
    end

    %verifica que el método exita
    if O > 1
        A = 0;
        E = "No existe el método";
    end

    % Método de Interpolación
    if O == 0
        M = zeros (N+1, N+1);
            % se usa un doble for anidado para constuir la matriz
             for k = 1:N+1
                 % Para elegir el punto que se usara para aporximar, se escoje el punto en "X"
                 % mas cercano a los puntos de "P"
                 if k == N+1
                     % si es el ultimo punto se verifica que se esoja el punto en "x" mas cercano
                     %al ultimo punto en el vector P, se obtiene el idx del vector "X"
                     [~,idx] = min(abs(X-P(length(P))));
                     y(k) = Y(idx)
                 else
                     [~,idx]=min(abs(X-P(k)));
                    y(k) = Y(idx)
                 end
                 for j = 1:N+1
                     %se contruye la matriz, se usa el punto x, elevado a la potencia correspodiente
                     M(k, j) = X(idx).^(j-1);
                end
            end
            % se calula el resultado con la multiplicacion de la matriz inversa por y
        A = inv(M) * y';
        E = 0;

        %funciones para graficar
        xGrafica=linspace(min(X),max(X));
        plot(X,Y,'.k','markersize',30)
        hold on, plot(xGrafica, evalua(xGrafica, A, N), 'r')
        hold on, plot(P, evalua(P, A, N), '.b','markersize',30)
    end

    %Método de mínimos cuadrados
    if O == 1
        M = zeros (N+1, N+1);
        % se usa un doble for anidado para constuir la matriz
         for k = 0:N
             for j = 0:N
                 %se usa la sumatoria del vector x elevado a la potencia correspodiente
                 M(k+1, j+1) = (sum(X.^(k+j)));
            end
        end

        % Se llena el vector "y" con el producto punto de "Y" y "X" elevado a la potencia correspodiente
        for k= 1:N+1
            y(k) = dot(Y , X.^(k-1))
        end

        A = inv(M) * y';
        E = 0;

        xGrafica=linspace(min(X),max(X));
        plot(X,Y,'.k','markersize',30)
        hold on, plot(xGrafica, evalua(xGrafica, A, N), 'r')
        hold on, plot(P, evalua(P, A, N), '.b','markersize',30)
    end

end

function y = evalua(x, A, N)
    y=0;
        for k = 1:N+1
            y+= A(k)*x.^(k-1);
        end
end
