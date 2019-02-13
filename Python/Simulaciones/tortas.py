#Daniel Charua A01017419

from random import *
from collections import Counter

utilidad1 = []
utilidad2 = []
utilidad3 = []
utilidad4 = []
utilidad5 = []
utilidad6 = []

for i in range(50000):
    rand = randint(1, 100);
    if (rand <= 5):
        tortas = 2 *12
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas - tortasVendidas
        if tortasSobrantes >= 0:
            utilidad1.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (3)) - (tortasVendidas *17))
        else:
            utilidad1.append(tortas*25 + tortasSobrantes *10 )

    if (rand > 5 and rand <= 15):
        tortas = 4 * 12
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas -tortasVendidas
        if tortasSobrantes >= 0:
            utilidad2.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (3)) - (tortasVendidas *17))
        else:
            utilidad2.append(tortas*25 + tortasSobrantes *10 )

    if (rand > 15 and rand <= 35):   
        tortas = 6 * 12
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas - tortasVendidas
        if tortasSobrantes >= 0:
            utilidad3.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (3)) - (tortasVendidas *17))
        else:
            utilidad3.append(tortas*25 + tortasSobrantes *10 )

    if (rand > 35 and rand <= 75):   
        tortas = 8 * 12 
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas -tortasVendidas
        if tortasSobrantes >= 0:
            utilidad4.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (3)) - (tortasVendidas *17))
        else:
            utilidad4.append(tortas*25 + tortasSobrantes *10 )

    if (rand > 75 and rand <= 95):   
        tortas = 10 * 12  
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas -tortasVendidas
        if tortasSobrantes >= 0:
            utilidad5.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (18)) - (tortasVendidas *2))
        else:
            utilidad5.append(tortas*25 + tortasSobrantes *10 )
            
    if (rand > 95 and rand <= 100):   
        tortas = 12 * 12   
        tortasVendidas = randint(1, 144);
        tortasSobrantes = tortas - tortasVendidas
        if tortasSobrantes >= 0:
            utilidad6.append((tortasVendidas*45) + ((tortasSobrantes/2) * 1.5) - (tortas * (18)) - (tortasVendidas *2))
        else:
            utilidad6.append(tortas*25 + tortasSobrantes  *10 )      

    

print("Guardando la materia prima para solo lo que vendes")
print ("2 Docenas %f" %(sum(utilidad1) / len(utilidad1)))    
print ("4 Docenas %f" %(sum(utilidad2) / len(utilidad2))) 
print ("6 Docenas %f" %(sum(utilidad3) / len(utilidad3))) 
print ("8 Docenas %f" %(sum(utilidad4) / len(utilidad4))) 
print ("10 Docenas %f" %(sum(utilidad5) / len(utilidad5))) 
print ("12 Docenas %f" %(sum(utilidad6) / len(utilidad6))) 