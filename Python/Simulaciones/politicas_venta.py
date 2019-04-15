from random import *

days = 50000
venta1 = 0
venta2 = 0
venta3 = 0

for i in range(days):
    random = randint(1, 100)

    if (random <= 60):
        venta1 += 100000
    elif (random > 60 and random <= 96):
        venta2 += 200000
    elif (random > 96 and random<= 100):
        venta3 += 240000

print("Totales primer dia: ", venta1)
print("Totales segundo dia: ", venta2)
print("Totales tercer dia: ", venta3)

print("Promedio primer dia: ", venta1/days)
print("Promedio segundo dia: ", venta2/days)
print("Promedio tercer dia: ", venta3/days)