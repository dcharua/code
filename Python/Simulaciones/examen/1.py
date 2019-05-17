#Daniel Charua A01017419
import numpy as np

def getLlegadas(num):
    if(num <= 20):
        res=1
    elif(num > 20 and num<= 45):
        res=2
    elif(num > 45 and num <= 75):
        res=3
    elif(num > 75 and num <= 90):
        res=4
    elif(num > 90 and num <= 100):
        res=5
    return res

def getSevicio(num):
    if(num <= 10):
        res=1
    elif(num > 10 and num<= 25):
        res=2
    elif(num > 25 and num <= 60):
        res=3
    elif(num > 60 and num <= 75):
        res=4
    elif(num > 75 and num <= 90):
        res=5
    elif(num > 90 and num <= 100):
        res=6
    return res

#llegadas = np.random.choice(np.arange(0, 5), p=[0.2, 0.25, 0.3, 0.15, 0.1])
#servicio =  np.random.choice(np.arange(0, 6), p=[0.1, 0.15, 0.35, 0.15, 0.15, 0.1])
llegadas = [52,37,82,69,98,96,33,50,88,90,50,27,45,81,66,74,30,59,67,28,2,74,35,24,3,29,60,74,85,90]
servicios = [60,60,80,53,69,37,6,63,57,2,94,52,69,33,32,30,48,88,33,48,72,33,62,13,74,68,22,44,42,9]
costo_humano = 16000/200/7
costo_construccion = 12000/200/7
costo_humano2 = (16000/200/7)*2
costo_construccion2 = 20000/200/7
minuto = 0
minuto_espera = 0
minuto_espera2 = 0
for i in range(len(llegadas)):
    llegada = getLlegadas(llegadas[i])
    servicio = getSevicio(servicios[i])
    minuto += llegada
    if (servicio > llegada):
        minuto_espera += abs(llegada - servicio) 

costo1 = minuto_espera + costo_humano+ costo_construccion
print(f'Costo de una ventanilla {costo1}')

ventanilla2 = 0
for i in range(len(llegadas)):
    llegada = getLlegadas(llegadas[i])
    servicio = getSevicio(servicios[i])
    ventanilla2 -= llegada
    minuto += llegada
    if (servicio > llegada):
        if ventanilla2 > 0:
            ventanilla2 =  abs(llegada - servicio) 
        else:
            minuto_espera2 += abs(llegada - servicio) 

costo2 = minuto_espera2 + costo_humano2 + costo_construccion2
print(f'Costo de dos ventanillas {costo2}')

print(f'Costo total una ventanilla {costo1 * 7 * 200}')

print(f'Costo total dos ventanilla {costo2 * 7 * 200}')