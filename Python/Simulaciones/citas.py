#Daniel Charua A01017419
from random import *

size = 50000
total = 0

for i in range(size):
    tipa = randint(1, 60)
    tipo = randint(1, 60)
    counter1 = tipo
    counter2 = tipa

    while (counter1 <= tipo + 20):
        counter1 += 1
        while (counter2 <= tipa + 15):
            counter2 += 1
            if(counter1 == counter2):
                total += 1

print('Encuentros: ', total)
print('posibilidad: ', (total/size))
