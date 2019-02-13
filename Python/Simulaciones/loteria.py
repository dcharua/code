#Daniel Charua A01017419

from random import *
from collections import Counter
rand1 = []
rand2 = []
rand3 = []
rand4 = []
rand5 = []
rand6 = []
price = 0
for i in range(50000):
    rand1.append(randint(1, 70))
    rand2.append(randint(1, 70))
    rand3.append( randint(1, 70))
    rand4.append( randint(1, 70))
    rand5.append( randint(1, 70))
    rand6.append(randint(1, 25))

print(Counter(rand1).most_common()[0])
print(Counter(rand2).most_common()[0])
print(Counter(rand3).most_common()[0])
print(Counter(rand4).most_common()[0])
print(Counter(rand5).most_common()[0])
print(Counter(rand6).most_common()[0])