# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
import argparse
from globalTypes import *
from RE import *
import sys
import re

#Golbal Functions
def globales(prog, pos, long):
    global programa
    global posicion
    global progLong
    programa = prog
    posicion = pos
    progLong = long 

def getToken(imprime = True):
    global posicion
    match = ''
    # Loop every regular Expresion defined in RE.py
    for regular_expresion in regular_expresions:
        pattern, token_type = regular_expresion
        # Using the re library to compile the regular expresion
        regex = re.compile(pattern)
        # if there is a match starting from current position
        match = regex.match(programa, posicion)
        #If there is a match we get the string that matched and update position
        if match:
            token_holder = match.group(0)
            posicion = match.end(0)
            #Error match handler
            if token_type == TokenType.ERROR:
                print("Error detected in character %s, number %d" % (token_holder, posicion))
            #If match is a space ignore it otherwise if imprime print it than return
            if token_type != TokenType.SPACE:
                if imprime:
                    print ('%s -> %s' %(token_type.name, token_holder))
                return token_type, token_holder
    #If there is no match print the error and update position
    if not match:
        print("Error detected in character %s  number %d" % (programa[posicion], posicion))
        posicion += 1       
        return(TokenType.ERROR, token_holder)
            