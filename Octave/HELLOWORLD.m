X= "Hello World";
disp(X); %Output
a = input("dame un numero: "); #Input
disp(a);

#Matriz
disp('Matrices');
m=[1 2 3; 4 5 6];
disp(m);
disp('Tamano de la matriz(filas columnas)');
size(m) #numero de filas y columnas de la matriz
disp('elemento de la fila 1 columna 2');
m(1,2)#imprime el elemento de la fila 1 y columna 2, en octave no hay elemento 0
disp('Matriz de unos');
ones(3,4) #Matriz de unos ( si dejo el ; despues de la funcion no imprime)
disp('Matriz de Ceros');
zeros(3,4) #Matriz de Ceros
disp('Matriz de numeros aletorios');
rand(2,5) #Matriz de numeros aletorios
disp('Matriz identidad');
eye(5) # Matriz identidad
disp('Cuadros magicos');
magic(3) #Cuadros magicos (suman la misma catidad por filas, columnas o diagonales)

#Vector
disp('Vectores');
v = [1 2 3 4 5 6]; #( si dejo el ; despues de la funcion no imprime)
disp(v);
disp('tamano');
length(v) #te da el tamaño del vector (no sirve con matrices)
v= 1:9 #Vector de uno a nueve
v= 1:0.1:2 #Vector empieza en 1 se le suma 0.1 y llega a 2

#Grafica y distribucion normal
disp('#Grafica y distribucion normal');
X= randn(1, 1000); # distribucion normal
hist(X) #grafica
