#Daniel Charua A01017419
import statistics
from random import *
import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt
from collections import Counter

efectivo = 0
efectivo_diario= []
dias = 50000
for i in range(dias):
    cantidad_random = randint(1, 100)
    if(cantidad_random <= 5):
        coches=3
    elif(cantidad_random > 5 and cantidad_random<= 20):
        coches=4
    elif(cantidad_random > 20 and cantidad_random <= 50):
        coches=5
    elif(cantidad_random > 50 and cantidad_random <= 75):
        coches=6
    elif(cantidad_random > 75  and cantidad_random <= 90):
        coches=7
    elif(cantidad_random > 90 and cantidad_random <= 100):
        coches=8
    for i in range(coches):
        tipo_coche = randint(1, 100)
        #Coche pequeño
        if(tipo_coche <= 45):
            operacion =  randint(1, 100)
            if(operacion <= 45):
                efectivo+= 350
            elif(operacion > 45 and operacion<= 60):
                efectivo+= 1575
            elif(operacion > 60 and operacion <= 80):
                efectivo+= 1925
            elif(operacion > 80 and operacion <= 90):
                efectivo+= 2540
            elif(operacion > 90 and  operacion <= 100):
                efectivo+= 700

        elif(tipo_coche > 45 and tipo_coche<= 80):
            operacion =  randint(1, 100)
            if(operacion <= 25):
                efectivo+= 550
            elif(operacion > 25 and operacion<= 50):
                efectivo+= 1975
            elif(operacion > 50 and operacion <= 65):
                efectivo+= 2545
            elif(operacion > 65 and operacion <= 85):
                efectivo+= 2925
            elif(operacion > 85 and  operacion <= 100):
                efectivo+= 700
            
        elif(tipo_coche > 80 and tipo_coche <= 100):
            operacion =  randint(1, 100)
            if(operacion <= 10):
                efectivo+= 750
            elif(operacion > 10 and operacion<= 25):
                efectivo+= 2275
            elif(operacion > 25 and operacion <= 55):
                efectivo+= 2845
            elif(operacion > 55 and operacion <= 95):
                efectivo+= 3415
            elif(operacion > 95  and operacion <= 100):
                efectivo+= 700
    efectivo_diario.append(efectivo)
    efectivo=0

print('Promedio de venta: %.2f ' %(statistics.mean(efectivo_diario)))
print('Mediana: %.2f' %(statistics.median(efectivo_diario)))
print('Moda: %.2f' %(statistics.mode(efectivo_diario)))
print('Desvacion estandar: %.2f' %(statistics.stdev(efectivo_diario)))
print('Varianza: %.2f' %(statistics.variance(efectivo_diario)))
print("Intervalo de confianza de 0.70: %.2f - %.2f" %(st.t.interval(0.70, len(efectivo_diario)-1, loc=np.mean(efectivo_diario), scale=st.sem(efectivo_diario))))
print("Intervalo de confianza de 0.80: %.2f - %.2f" %(st.t.interval(0.85, len(efectivo_diario)-1, loc=np.mean(efectivo_diario), scale=st.sem(efectivo_diario))))
print("Intervalo de confianza de 0.90: %.2f - %.2f" %(st.t.interval(0.90, len(efectivo_diario)-1, loc=np.mean(efectivo_diario), scale=st.sem(efectivo_diario))))
print("Intervalo de confianza de 0.95: %.2f - %.2f" %(st.t.interval(0.95, len(efectivo_diario)-1, loc=np.mean(efectivo_diario), scale=st.sem(efectivo_diario))))
print("Intervalo de confianza de 0.99: %.2f - %.2f" %(st.t.interval(0.99, len(efectivo_diario)-1, loc=np.mean(efectivo_diario), scale=st.sem(efectivo_diario))))

   
                    
# Histograma
n, bins, patches = plt.hist(x=efectivo_diario, bins='auto', color='#0504aa',
                            alpha=0.7, rwidth=0.85)
plt.grid(axis='y', alpha=1)
plt.xlabel('Dias')
plt.ylabel('Efectivo')
plt.title('Histograma llamadas')

maxfreq = n.max()
# Set a clean upper y-axis limit.
plt.show()