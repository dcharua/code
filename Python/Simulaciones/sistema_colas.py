#Daniel Charua A01017419
import statistics
from random import *
import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt
from collections import Counter


dias = 50000
costos_diario= []
personal = 3


def getCamionesCola():
    cola_random = randint(1, 100)
    if(cola_random <= 50):
        camiones_cola=0
    elif(cola_random >50 and cola_random<= 75):
        camiones_cola=1
    elif(cola_random > 75 and cola_random <= 90):
        camiones_cola=2
    elif(cola_random > 90 and cola_random <= 100):
        camiones_cola=3
    return camiones_cola

def getTiempoLlegada():
    tiempo_llegada = randint(1, 100) 
    if(tiempo_llegada <= 2):
        minutos=20
    elif(tiempo_llegada > 2 and tiempo_llegada<= 10):
        minutos=25
    elif(tiempo_llegada > 10 and tiempo_llegada <= 22):
        minutos=30
    elif(tiempo_llegada > 22 and tiempo_llegada <= 47):
        minutos=35
    elif(tiempo_llegada > 47 and tiempo_llegada <= 67):
        minutos=40
    elif(tiempo_llegada > 67 and tiempo_llegada <= 82):
        minutos=45
    elif(tiempo_llegada > 82 and tiempo_llegada <= 92):
        minutos=50
    elif(tiempo_llegada > 92 and tiempo_llegada <= 97):
        minutos=55
    elif(tiempo_llegada > 97 and tiempo_llegada <= 100):
        minutos=60   
    return minutos

def getTiempoDescarga(numero_equipo=3):
    tiempo_descarga = randint(1, 100) 
    if(numero_equipo==3):
        if(tiempo_descarga <= 5):
            minutos=20
        elif(tiempo_descarga > 5 and tiempo_descarga<= 15):
            minutos=25
        elif(tiempo_descarga > 15 and tiempo_descarga <= 35):
            minutos=30
        elif(tiempo_descarga > 35 and tiempo_descarga <= 60):
            minutos=35
        elif(tiempo_descarga > 60 and tiempo_descarga <= 72):
            minutos=40
        elif(tiempo_descarga > 72 and tiempo_descarga <= 82):
            minutos=45
        elif(tiempo_descarga > 82 and tiempo_descarga <= 90):
            minutos=50
        elif(tiempo_descarga > 90 and tiempo_descarga <= 96):
            minutos=55
        elif(tiempo_descarga > 96 and tiempo_descarga <= 100):
            minutos=60 

    elif(numero_equipo==4):           
        if(tiempo_descarga <= 5):
            minutos=15
        elif(tiempo_descarga > 5 and tiempo_descarga<= 20):
            minutos=20
        elif(tiempo_descarga > 20 and tiempo_descarga <= 40):
            minutos=25
        elif(tiempo_descarga > 40 and tiempo_descarga <= 60):
            minutos=30
        elif(tiempo_descarga > 60 and tiempo_descarga <= 75):
            minutos=35
        elif(tiempo_descarga > 75 and tiempo_descarga <= 87):
            minutos=40
        elif(tiempo_descarga > 87 and tiempo_descarga <= 95):
            minutos=45
        elif(tiempo_descarga > 95 and tiempo_descarga <= 99):
            minutos=50
        elif(tiempo_descarga > 99 and tiempo_descarga <= 100):
            minutos=55

    elif(numero_equipo==5):
        if(tiempo_descarga <= 10):
            minutos=10
        elif(tiempo_descarga > 10 and tiempo_descarga<= 28):
            minutos=15
        elif(tiempo_descarga > 28 and tiempo_descarga <= 50):
            minutos=20
        elif(tiempo_descarga > 50 and tiempo_descarga <= 68):
            minutos=25
        elif(tiempo_descarga > 68 and tiempo_descarga <= 78):
            minutos=30
        elif(tiempo_descarga > 78 and tiempo_descarga <= 86):
            minutos=35
        elif(tiempo_descarga > 86 and tiempo_descarga <= 92):
            minutos=40
        elif(tiempo_descarga > 92 and tiempo_descarga <= 97):
            minutos=45
        elif(tiempo_descarga > 97 and tiempo_descarga <= 100):
            minutos=50     

    elif(numero_equipo==6):
        if(tiempo_descarga <= 12):
            minutos=5
        elif(tiempo_descarga > 12 and tiempo_descarga<= 27):
            minutos=10
        elif(tiempo_descarga > 27 and tiempo_descarga <= 53):
            minutos=15
        elif(tiempo_descarga > 53 and tiempo_descarga <= 68):
            minutos=20
        elif(tiempo_descarga > 68 and tiempo_descarga <= 80):
            minutos=25
        elif(tiempo_descarga > 80 and tiempo_descarga <= 88):
            minutos=30
        elif(tiempo_descarga > 88 and tiempo_descarga <= 94):
            minutos=35
        elif(tiempo_descarga > 94 and tiempo_descarga <= 98):
            minutos=40
        elif(tiempo_descarga > 98 and tiempo_descarga <= 100):
            minutos=45             
    
    return minutos

for i in range (4):
    for i in range(dias):
        hora = 0
        tiempo_camiones_esperando = 0
        costos = 0
        horas_extra = 0    
        jornada_trabajo = 540
        cola_camiones = getCamionesCola()
        tiempo_llegada = getTiempoLlegada()
        tiempo_descarga = getTiempoDescarga(personal)

        #si hay camiones en el t=0 sacamos de la cola al primer camion
        if cola_camiones > 0:
            cola_camiones -= 1
        #Si no hay camiones esperando de inicio adelantamos el reloj      
        else:
            hora += tiempo_llegada

        while hora < jornada_trabajo:
            #Camion llego mientras se descarga
            if tiempo_llegada < tiempo_descarga:
                hora += tiempo_llegada
                tiempo_camiones_esperando += cola_camiones * tiempo_llegada 
                cola_camiones +=1
                tiempo_descarga -= tiempo_llegada
                tiempo_llegada = getTiempoLlegada()

            #Camion llego despues de descarga
            else:
                hora += tiempo_descarga
                tiempo_camiones_esperando += cola_camiones * tiempo_descarga
                tiempo_llegada -= tiempo_descarga
                #Si hay camiones en cola
                if cola_camiones > 0:
                    cola_camiones-=1
                # de lo contrario adelantamos el reloj   
                else:
                    hora +=tiempo_llegada
                    tiempo_llegada=0    
                tiempo_descarga = getTiempoDescarga(personal)
        #Si se acabo la jornada y siguem camiones | tiempo extra
        while cola_camiones > 0:
            horas_extra += getTiempoDescarga(personal)
            cola_camiones -=1

        costos_personal = (personal * 8 * 25) + (personal * horas_extra * 37.5)
        costos_espera = (tiempo_camiones_esperando/60) * 100
        costos_almacen = (hora /60) * 500 + horas_extra * 500
        costos_total = costos_personal + costos_espera + costos_almacen
        costos_diario.append(costos_total)

    print("Equipo de %d" %(personal))
    print('Promedio de costos: %.2f ' %(statistics.mean(costos_diario)))
    print('Mediana: %.2f' %(statistics.median(costos_diario)))
    print('Moda: %.2f' %(statistics.mode(costos_diario)))
    print('Desvacion estandar: %.2f' %(statistics.stdev(costos_diario)))
    print('Varianza: %.2f' %(statistics.variance(costos_diario)))
    print("Intervalo de confianza de 0.95: %.2f - %.2f" %(st.t.interval(0.95, len(costos_diario)-1, loc=np.mean(costos_diario), scale=st.sem(costos_diario))))
    print("---------------------------------------------")
    personal +=1