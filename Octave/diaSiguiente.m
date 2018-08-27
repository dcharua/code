# Daniel Charua     A01017419     Proyecto 0   Métodos numéricos
function fecha = diaSiguiente(D, M, A)
    if(D==31 && M==12)
        #Primer if para checar si es el ultimo dia del año, en ese caso se aumenta el año y se cambia a 1ero de enero
        A++;
        fecha=[1, 1, A];
    elseif (D < 28 || (D == 28 && M == 2 && mod(A,4) == 0) || (D == 29 && M != 2) || (D == 30 && (M < 8 && mod(M,2) == 1 ||  M > 6 && mod(M,2) == 0)))
        #Segundo if para checar que no sea el ultimo dia del mes (en ese caso se aumenta el dia)
        #1.- se checa si es menor a 28 (minimo para que sea final de mes), 2.-  si es 28 y febrero se checa si es bisiesto
        #3.- si 29 se verifica que no sea febrero, 4.- si es 30 se checa que sea mes de 31 dias(los primeros 7 meses si es impar, los siguientes si es par)
        D++;
        fecha=[D, M, A];
    else
        # si no entra en las demas categorias es porque se cambia al primer dia del siguiente mes
        M++;
        fecha=[1, M, A];
    end
end
