import random
import numpy as np

noCero = 0.0000000001
repeticionesDeLaSimulacion = 10000;

tiempoOptimo = 1200 # TIEMPO OPTIMO POR CORRIDA

sacarPicklist = 35.55 # TIEMPO PROMEDIO PARA SACAR LA PICKLIST
tiempoRackVacio = 100.5
tiempoChoqueDeRuta = 120
tiempoDescargaPorModulo = 278
modulosADescargar = 2

def numeroAleatorio(min, max):
    return min+random.randrange(max-min)

def promedio(array):
    return sum(array) / len(array)

def choqueDeRuta():
    probabilidad = random.random() + noCero
    tiempo = 0
    if probabilidad > 0 and probabilidad <= 0.5:
        tiempo = 0
    if probabilidad > 0.5 and probabilidad <= 1:
        tiempo = tiempoChoqueDeRuta
    return tiempo

def rackVacio():
    probabilidad = random.random() + noCero
    tiempo = 0
    if probabilidad > 0 and probabilidad <= 0.083:
        tiempo = 0
    if probabilidad > 0.083 and probabilidad <= 1:
        tiempo = tiempoRackVacio
    return tiempo

def avanzaRuta(probabilidad):
    segundos = 0
    if probabilidad > 0 and probabilidad <= 0.381:
        segundos = numeroAleatorio(1,10)
    if probabilidad > 0.381 and probabilidad <= 0.762:
        segundos = numeroAleatorio(11,20)
    if probabilidad > 0.762 and probabilidad <= 0.809:
        segundos = numeroAleatorio(21,30)
    if probabilidad > 0.809 and probabilidad <= 0.856:
        segundos = numeroAleatorio(31,40)
    if probabilidad > 0.856 and probabilidad <= 0.903:
        segundos = numeroAleatorio(41,50)
    if probabilidad > 0.903 and probabilidad <= 0.95:
        segundos = numeroAleatorio(51,60)
    if probabilidad > 0.95 and probabilidad <= 1:
        segundos = numeroAleatorio(61,70)
    return segundos

def revisaPicklist(probabilidad):
    segundos = 0
    if probabilidad > 0 and probabilidad <= 0.222:
        segundos = numeroAleatorio(1,5)
    if probabilidad > 0.222 and probabilidad <= 0.555:
        segundos = numeroAleatorio(6,10)
    if probabilidad > 0.555 and probabilidad <= 0.888:
        segundos = numeroAleatorio(11,15)
    if probabilidad > 0.888 and probabilidad <= 1:
        segundos = numeroAleatorio(16,20)
    return segundos

def cargaMaterial(probabilidad):
    segundos = 0
    if probabilidad > 0 and probabilidad <= 0.083:
        segundos = numeroAleatorio(1,10)
    if probabilidad > 0.083 and probabilidad <= 0.291:
        segundos = numeroAleatorio(11,20)
    if probabilidad > 0.291 and probabilidad <= 0.457:
        segundos = numeroAleatorio(21,30)
    if probabilidad > 0.457 and probabilidad <= 0.707:
        segundos = numeroAleatorio(31,40)
    if probabilidad > 0.707 and probabilidad <= 0.832:
        segundos = numeroAleatorio(41,50)
    if probabilidad > 0.832 and probabilidad <= 0.873:
        segundos = numeroAleatorio(51,60)
    if probabilidad > 0.873 and probabilidad <= 0.915:
        segundos = numeroAleatorio(61,70)
    if probabilidad > 0.915 and probabilidad <= 1:
        segundos = numeroAleatorio(71,80)
    return segundos

def correrRuta():
    tiempoCorrida = 0
    numeroMateriales = 0

    # ANADIR EL TIEMPO QUE TOMA SACAR LA PICKLIST
    tiempoCorrida += sacarPicklist

    # ANADIR TIEMPO DE AVANCE DE RUTA DESPUES DE RECOGER LA PICKLIST
    tiempoCorrida += avanzaRuta(random.random() + noCero)

    # ANADIR EL TIEMPO SI SE ATRAVIEZA OTRA RUTA ALEATORIAMENTE
    tiempoCorrida += choqueDeRuta()

    # ANADIR EL TIEMPO SI HAY UN RACK VACIO
    tiempoCorrida += rackVacio()

    # ANADIR TIEMPO DE AVANCE DE RUTA ANTES DE RECOGER LA PICKLIST
    tiempoCorrida += avanzaRuta(random.random() + noCero)

    # ANADIR EL TIEMPO DE LA DESCARGA DE MATERIAL
    tiempoCorrida += (modulosADescargar*tiempoDescargaPorModulo)

    while tiempoCorrida < tiempoOptimo:
        tiempoCorrida += revisaPicklist(random.random() + noCero)
        tiempoCorrida += avanzaRuta(random.random() + noCero)
        tiempoCorrida += cargaMaterial(random.random() + noCero)
        numeroMateriales += 1

    return numeroMateriales, tiempoCorrida

def simularRutas():
    diferentesNumeroDeMateriales = []
    diferentesTiemposPorCorrida = []

    for x in range(repeticionesDeLaSimulacion):
        corrida = correrRuta()
        diferentesNumeroDeMateriales.append(corrida[0])
        diferentesTiemposPorCorrida.append(corrida[1])

    print ("Numero promedio de materiales por corrida =", promedio(diferentesNumeroDeMateriales))
    print ("Tiempo promedio por corrida =", promedio(diferentesTiemposPorCorrida))
    

simularRutas()
