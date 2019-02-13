#Daniel Charua A01017419
import statistics
import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt
from random import *
from collections import Counter

ganacia = []
ganaciaHombre = []
ganaciaMujer = []
llamadas = 500000
for i in range(llamadas):
    contestan = randint(1, 100)
    
    if (contestan <= 30):
        genero = randint(1, 100)
        #hombre
        if (genero >= 80):
            venta = randint(1, 100)
            if (venta <= 25):
                credito = randint(1, 100)
                if (credito <= 10):
                    ganacia.append(200)
                    ganaciaHombre.append(200)
                if (credito > 10 and credito <= 50):
                    ganacia.append(400) 
                    ganaciaHombre.append(400)  
                if (credito >50 and credito <= 80):
                    ganacia.append(600)     
                    ganaciaHombre.append(600)  
                if (credito > 80 and credito <= 100):
                    ganacia.append(800)    
                    ganaciaHombre.append(800)

        if (genero < 80):  
            venta = randint(1, 100)
            if (venta <= 15):
                credito = randint(1, 100)
                if (credito <= 60):
                    ganacia.append(200)
                    ganaciaMujer.append(200)
                if (credito > 60 and credito <= 90):
                    ganacia.append(400)   
                    ganaciaMujer.append(400)
                if (credito > 90 and credito <= 100):
                    ganacia.append(600) 
                    ganaciaMujer.append(600)  
                    
                        
print('Promedio de venta: %.2f ' %(statistics.mean(ganacia)))
print('Mediana: %.2f' %(statistics.median(ganacia)))
print('Moda: %.2f' %(statistics.mode(ganacia)))
print('Desvacion estandar: %.2f' %(statistics.stdev(ganacia)))
print('Varianza: %.2f' %(statistics.variance(ganacia)))
print("Intervalo de confianza de 0.95: %.2f - %.2f" %(st.t.interval(0.95, len(ganacia)-1, loc=np.mean(ganacia), scale=st.sem(ganacia))))
print ("Ganancia mensual de %d llamadas: %.2f" %( llamadas /12 , sum(ganacia) /12)) 
print ("Promedio por llamada: %.2f" %( sum(ganacia) /llamadas)) 
print ("Ganancia Hombre %.2f -- Ganancia Mujer: %.2f" %( sum(ganaciaHombre), sum(ganaciaMujer) ))
print ("Promedio por llamada Hombre %.2f -- Promedio por llamada Mujer: %.2f" %( (sum(ganaciaHombre)/len(ganaciaHombre)), (sum(ganaciaMujer)/len(ganaciaMujer) )))

# Histograma
n, bins, patches = plt.hist(x=ganacia, bins='auto', color='#0504aa',
                            alpha=0.7, rwidth=0.85)
plt.grid(axis='y', alpha=0.75)
plt.xlabel('Ganancia')
plt.ylabel('llamadas')
plt.title('Histograma llamadas')
plt.text(23, 45, r'$\mu=15, b=3$')
maxfreq = n.max()
# Set a clean upper y-axis limit.
plt.ylim(ymax=np.ceil(maxfreq / 10) * 10 if maxfreq % 10 else maxfreq + 10)
plt.show()