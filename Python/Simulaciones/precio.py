#Daniel Charua A01017419

from random import *
from collections import Counter

price = 0

for i in range(500000):
    rand = randint(0, 99)
    if (rand >= 20):
        price = price + 99
    else :
        price = price + 100
print(price/500000)
