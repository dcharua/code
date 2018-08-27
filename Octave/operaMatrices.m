function [R, E, M]= operaMatrices (A, B, N)
    [M1, N1] = size (A); #se obtiene eltamaño de A
    [M2, N2] = size (B);#se obtiene eltamaño de B
    if (N < 2 && (M1 != M2 || N1 != N2)) # Se checa que las matrices sean iguales para suma resta
        R = "Error";
        E = 1;
        M = "Las dimensiones de las matrices impide su suma/resta";
    elseif (N==0) #Caso suma
        R = sumaM(A, B, M1, N1);
        E = 0;
        M = "No hay error";
    elseif (N==1) # Caso Resta
        R = restaM(A, B, M1, N1);
        E = 0;
        M = "No hay error";
    elseif (N==2) # Caso multiplicacion
        if(M2 == N1 && N2 == M1) # se checa que el numero de filas y columnas sean iguales
            R = multiplicaM(A, B, M1, N1, N2);
            E = 0;
            M = "No hay error";
        else
            R = "Error";
            E = 1;
            M = "las dimensiones de las matrices impide su multicacion";
        end
    elseif (N==3) # Caso media, desvicion estandar
        R = mediaM(A, M1, N1);
        E = 0;
        M = "No hay error";
    elseif (N==4) # Caso maximo minimo
        R = maxMinM(A, M1, N1);
        E = 0;
        M = "No hay error";
    elseif (N > 4 || N < 0 )# Caso no existe la operacion
        R = "Error";
        E = 1
        M = "Operación NO EXISTE";
    end
end

function R1 = sumaM(A, B, M1, N1)
    for k = 1:M1
        for g= 1:N1
            R1(k, g) = A(k, g) + B(k,g); # se recore matrices sumando las pocisiones iguales
        end
    end
end

function R1 = restaM(A, B, M1, N1)
    for k = 1:M1
        for g= 1:N1
            R1(k, g) = A(k, g) - B(k, g); # se recore matrices restando las pocisiones iguales
        end
    end
end

function R1 = multiplicaM(A, B, M1, N1, N2)
    R1 = zeros (M1, N2);
    for k = 1:M1
        for g= 1:N2
            for h = 1:N1
                R1(k, g) += A(k, h) * B(h, g); # se recoren las matrices, se usa un tercer for para recorrer fila de la primer columna de la segunda
            end
        end
    end
end

function R1 = mediaM(A, M1, N1)
    for k = 1:M1
        media = mean(A(k, 1:N1)); # se le manda todo la fila para encontar la media
        des = std(A(k, 1:N1)); # se le manda todo la fila para encontar la desviacion estandar
        R1(k,1:2)= [media, des]; # se almacenan por filas primera columna media, segunda desvicion
    end
end

function R1 = maxMinM(A, M1, N1)
    for k = 1:N1
        mayor = max(A(1:M1, k)); #se le manda toda la columna para encontar el maximo
        menor = min(A(1:M1, k)); #se le manda toda la columna para encontar el minimo
        R1(1:2, k) = [mayor; menor]; # se almacenan por columanas, arriba el maximo abajo el minimo
    end
end
