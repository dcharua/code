#Daniel charua A0101719
from random import *
import matplotlib.pyplot as plt
import numpy as np
from collections import Counter
import statistics
import scipy.stats as stats

size = 5000
tipo1 = []
tipo2 = []

for i in range(size):
    random = randint(1, 100)

    if (random <= 40):
        punto = np.random.triangular(2, 3, 4)
        extra = np.random.exponential(6)
        punto_final = punto + extra
        tipo1.append(punto_final)
    elif (random > 40 and random <= 100):
        punto2 = np.random.triangular(1, 4, 7)
        extra2 = np.random.exponential(6)
        punto_final2 = punto2 + extra2
        tipo2.append(punto_final2)

h = plt.hist(tipo1, bins=200, density=True)
h2 = plt.hist(tipo2, bins=200, density=True)
print('Promedio 1: %.2f' %(statistics.mean(tipo1)))
print('Promedio 2: %.2f' %(statistics.mean(tipo2)))
plt.show()


