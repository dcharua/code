# Daniel Charua A01017419
from random import *
import numpy as np
from scipy.stats import poisson
import matplotlib.pyplot as plt

size = 100
count1 = 0
count2 = 0
count3 = 0
count4 = 0
count5 = 0
count6 = 0
count7 = 0
count8 = 0
count9 = 0
count10 = 0
count11 = 0
count12 = 0
total = 0

for i in range(size):
    random = randint(1, 100)

    if (random <= 19):
        count1 += 1

    elif (random > 19 and random <= 25):
        count2 += 1
        total += 5000
    elif (random > 25 and random <= 40):
        count3 += 1
        total += 10000
    elif (random > 40 and random <= 60):
        count4 += 1
        total += 15000
    elif (random > 60 and random <= 72):
        count5 += 1
        total += 20000
    elif (random > 72 and random <= 80):
        count6 += 1
        total += 30000
    elif (random > 80 and random <= 86):
        count7 += 1
        total += 40000
    elif (random > 86 and random <= 91):
        count8 += 1
        total += 50000
    elif (random > 91 and random <= 95):
        count9 += 1
        total += 60000
    elif (random > 95 and random <= 98):
        count10 += 1
        total += 70000
    elif (random > 98 and random <= 99):
        count11 += 1
        total += 80000
    elif (random > 99 and random <= 100):
        count12 += 1
        total += 100000

s1 = np.random.poisson(count1, size)
s2 = np.random.poisson(count2, size)
s3 = np.random.poisson(count3, size)
s4 = np.random.poisson(count4, size)
s5 = np.random.poisson(count5, size)
s6 = np.random.poisson(count6, size)
s7 = np.random.poisson(count7, size)
s8 = np.random.poisson(count8, size)
s9 = np.random.poisson(count9, size)
s10 = np.random.poisson(count10, size)
s11 = np.random.poisson(count11, size)
s12 = np.random.poisson(count12, size)

