#Daniel Charua A01017419

from random import *
from collections import Counter

positionx = 0
positiony = 0
close = 0

positions = []

for i in range(50000):
    for y in range (10):
        rand = randint(1, 4)
        if (rand == 1):
            positionx = positionx -1

        elif (rand == 2):
            positionx = positionx + 1

        elif(rand == 3):
            positiony = positiony + 1

        elif(rand == 4):     
            positiony= positiony -1

    final = abs(positionx) + abs(positiony)
    if(final <= 2):
        close = close + 1
    
    positions.append((positionx, positiony))        
    positionx = 0
    positiony = 0 
lst = Counter(positions).most_common()
print(lst[0])
highest_count = max([i[1] for i in lst])
values = [i[0] for i in lst if i[1] == highest_count]
print ('procentaje de +/- 2 cuadras ' + str(close/50000))  

print ('posicion mas comun ' +  str(values))


    
