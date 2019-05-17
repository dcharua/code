#Daniel Charua A01017419


import numpy as np
import random

I = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
R = np.array([[.05, .1, 0, 0, 0, 0], [.02, 0, .2, .5, 0, 0], [.01, 0, 0, 0, .6, .2]])
Q = np.array([[.3, .55, 0], [0, .2, .08], [0, 0, .19]])
F = np.linalg.inv(np.subtract(I, Q))
FR = np.matmul(F, R)
print("Probabilidad de que un recien nacido muera: {} %".format(round(FR[0][0],2) * 100))
ganancia = 0
for i in range(1000):
    rand = random.random()
    # Venta nivel 1
    if rand <= FR[0][1]:
        ganancia += 2000
    elif FR[0][1] < rand <= FR[0][2]:
        ganancia += 3000
    elif FR[0][2] < rand <= FR[0][3]:
        ganancia += 5000
    elif FR[0][3] < rand <= FR[0][4]:
        ganancia += 10000
    elif FR[0][4] < rand <= FR[0][5]:
        ganancia += 20000
print("La ganancia promedio para un animal recien nacido es de {}".format(ganancia/1000))