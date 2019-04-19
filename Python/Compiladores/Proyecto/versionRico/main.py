# Mauricio Rico
# script de prueba

from globalTypes import *
from Parser1 import *

f = open('sample.c-', 'r')

programa = f.read()     # lee todo el archivo a compilar
progLong = len(programa)   # longitud original del programa
programa = programa + '$'   # agregar un caracter $ que represente EOF
posicion = 0       # posición del caracter actual del string

globales(programa, posicion, progLong) # función para pasar los valores iniciales de las variables globales

AST = parser(True)
