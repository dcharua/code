#Daniel Charua A01017419
costo_p = 8
costo_hora = 50
horas1 = 0 
horas4 = 0
p4_tiempo = 2
p1_tiempo = 1
costosp1 = 0
costosp4 = 0

def getTime1(num):
    if(num <= 5):
        res=10
    elif(num > 5 and num<= 20):
        res=20
    elif(num > 20 and num <= 35):
        res=30
    elif(num > 35 and num <= 55):
        res=40
    elif(num > 55 and num <= 75):
        res=50
    elif(num > 75 and num <= 90):
        res=60
    elif(num > 90 and num <= 100):
        res=70
    return res

def getTime4(num):
    if(num <= 15):
        res=100
    elif(num > 15 and num<= 40):
        res=110
    elif(num > 40 and num <= 75):
        res=120
    elif(num > 75 and num <= 95):
        res=130
    elif(num > 95 and num <= 100):
        res=140
    return res

pen1 = [47,3,11,10,67,23,89,62,56,74]
pen4 = [99,29,27,75,89,78,68,64,62,30]

for i in range(len(pen1)):
    p1 = getTime1(pen1[i])
    p4 = getTime4(pen4[i])
    horas1 += p1 
    horas4 += p4
    costosp1 += 58
    costosp4 += 132

costosp1_total = costosp1 / horas1
costosp4_total = costosp4 / horas4
print(f'\nCosto de por hora de cambiar 1 {costosp1_total}')
print(f'\nCosto de por hora de cambiar 4 {costosp4_total}')