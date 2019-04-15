# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
import argparse
import globalTypes
from RE import *
import sys
import re


def getToken(imprime = True):
    match = ''
    
    # Loop every regular Expresion defined in RE.py
    for regular_expresion in regular_expresions:
        pattern, token_type = regular_expresion
        # Using the re library to compile the regular expresion
        regex = re.compile(pattern)
        # if there is a match starting from current position
        match = regex.match(globalTypes.programa, globalTypes.posicion)
        #If there is a match we get the string that matched and update position
        if match:
            token_holder = match.group(0)
            globalTypes.posicion = match.end(0)
            #Error match handler
            if token_type == TokenType.ERROR:
                print("Error detected in character %s line %d, number %d" % (token_holder, globalTypes.programa[:globalTypes.posicion].count('\n'), globalTypes.posicion - globalTypes.programa[:globalTypes.posicion].rfind('\n')))
            #If match is a space ignore it otherwise if imprime print it than return()
            if token_type != TokenType.SPACE:
                if imprime:
                    print ('%s  %s' %(token_type.name, token_holder))
                return token_type, token_holder
    #If there is no match print the error and update position
    if not match:
        printError()
        posicion += 1       
        return(TokenType.ERROR, token_holder)

def printError():
    pointer = '^'
    print("Error detected in character %s line %s, number %d" % (globalTypes.programa[globalTypes.posicion], globalTypes.programa[:globalTypes.posicion].count('\n'), globalTypes.posicion - globalTypes.programa[:globalTypes.posicion].rfind('\n')))
    print((globalTypes.programa[globalTypes.programa[:globalTypes.posicion].rfind('\n'):(globalTypes.programa.rfind("\n")-2)]))
    pointer = pointer.rjust(globalTypes.posicion - globalTypes.programa[:globalTypes.posicion].rfind('\n'))
    print(pointer)