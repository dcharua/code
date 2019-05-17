import numpy as np

print("Problema 19.")

count = 0
iterations = 10000
waiting_trucks = 0

for j in range(iterations):
    for i in range(8):
        trucks_arrived = np.random.poisson(3)
        waiting_trucks += trucks_arrived
        if waiting_trucks > 3:
            count += 1
        served_trucks = np.round(np.random.exponential(4))
        waiting_trucks -= served_trucks
        if waiting_trucks < 0:
            waiting_trucks = 0

print("\t La probabilidad de que haya mas de tres camiones esperando o siendo cargados es de: ", count/(iterations * 8) * 100, "%")

#Despejando la formula, la clave es asumir que p1 + p2 + p3 tiene que ser igual a 1.
p1 = 0.26 
p3 = 0.3 - p1
g1 = (0.14 - 0.5*p1)/0.2
g2 = 0.4 - g1
h2 = (0.07 - 0.2*g2)/0.3
h3 = 0.2 - h2

print("\nProblema 22 (El orden de las matrices es: [Hicourt industries, Printing House, Gandy Printers])")
matrix = np.array([[0.8,h2,h3],[p1,0.7,p3],[g1,g2,0.6]])
s = np.array([0.3,0.5,0.2])
matrix_a = s
for i in range(100):
    matrix_a = np.matmul(matrix_a, matrix)
print("\ta) George no va a cumplir su meta ya que la cadena de markov ocasiona que se equilibren nuevamente el mercado. A continuacion esta la proyeccion a 100 meses:\n\t", matrix_a)
print("\t\t Sin embargo, se puede notar que George va a tener la mayor cantidad del mercado.")
matrix_a = s
for i in range(1000):
    matrix_a = np.matmul(matrix_a, matrix)
print("\tb) Una proyeccion a mil meses muestra que las acciones son: \n\t", matrix_a, "\n\t\tEsto nos dice que las acciones parecen mantenerse en equilibrio en estos niveles. Siendo esta la proyeccion al largo plazo.")
#print("\t",np.matmul(s,matrix_power(matrix,1)))
print("\tc) Claramente no, como se ve en los resultados, las acciones parecen mantenerse siempre entre los mismos niveles, nunca lo suficientemente baja para sacar a Printing House del mercado. Sin embargo, si para convertirse en la empresa mas importante.")
print("\n")


print("Problema 28")

initial_shares = np.array([0.6,0.1,0.1,0.1,0.05,0.01,0.01,0.01,0.01,0.01])

from_1 = np.array([0.6,0.1,0.1,0.1,0.05,0.01,0.01,0.01,0.01, 0.01])
from_2 = np.array([0.01,0.8,0.01,0.01,0.01,0.1,0.01,0.01,0.01, 0.03])
from_3 = np.array([0.01,0.01,0.7,0.01,0.01,0.1,0.01,0.05,0.05, 0.05])
from_4 = np.array([0.01,0.01,0.01,0.9,0.01,0.01,0.01,0.01,0.01, 0.02])
from_5 = np.array([0.01,0.01,0.01,0.1,0.8,0.01,0.03,0.01,0.01, 0.01])
from_6 = np.array([0.01,0.01,0.01,0.01,0.01,0.91,0.01,0.01,0.01, 0.01])
from_7 = np.array([0.01,0.01,0.01,0.01,0.01,0.1,0.7,0.01,0.1, 0.04])
from_8 = np.array([0.01,0.01,0.01,0.01,0.01,0.1,0.03,0.8,0.01, 0.01])
from_9 = np.array([0.01,0.01,0.01,0.01,0.01,0.1,0.01,0.1,0.7, 0.04])
from_10 = np.array([0.01,0.01,0.01,0.01,0.01,0.1,0.1,0.05,0, 0.7])

all_transformations = np.array([from_1, from_2, from_3, from_4, from_5, from_6, from_7, from_8, from_9, from_10])

print("\ta) Las market shares para las tiendas en el siguiente periodo, ordenadas en el mismo orden, son: \n\t", np.matmul(initial_shares, all_transformations))
current_shares = initial_shares
for i in range(1000):
    current_shares = np.matmul(current_shares, all_transformations)
print("\tb) Las market shares en equilibrio son: \n\t", current_shares)

print("\tc) Con el cambio de Sandy, los resultados son:")
corrected_initial_shares = np.array([0.4,0.3,0.1,0.1,0.05,0.01,0.01,0.01,0.01,0.01])
print("\t  Siguiente periodo: \n\t", np.matmul(corrected_initial_shares, all_transformations))
current_shares = corrected_initial_shares
for i in range(1000):
    current_shares = np.matmul(current_shares, all_transformations)
print("\tLas market shares en equilibrio son: \n\t", current_shares)
print("\tO sea, el mismo equilibrio.")
print("\td) El nuevo equilibrio, calculado en 10000 meses, con estos parametros es:")
from_1_corrected = ([0.99,0.01,0,0,0,0,0,0,0,0])
all_transformations_corrected = np.array([from_1_corrected, from_2, from_3, from_4, from_5, from_6, from_7, from_8, from_9, from_10])
current_shares = corrected_initial_shares
for i in range(10000):
    current_shares = np.matmul(current_shares, all_transformations_corrected)
print("\t", current_shares)

print("\t El equilibrio cambia, pero no, no va a poder alcanzar el 90% al largo plazo")