# Mauricio Rico
# lexer

import globalTypes
from globalTypes import *
import sys
import lex
import re

# # funcion para los globales
# def globales(prog, pos, long):
#     global programa
#     global posicion
#     global progLong
#     programa = prog
#     posicion = pos
#     progLong = long
#     lexer.input(programa)

tokens = [] # tokens para lex

for token in TokenType:
    tokens.append(token.name) # pasar de tokentype a la lista de tokens para lex

# reserved = {
#     'if' : 'IF',
#     'else' : 'ELSE',
#     'while' : 'WHILE',
#     'void' : 'VOID',
#     'return': 'RETURN',
#     'int': 'INT'
# }

#tokens = tokens + list(reserved.values()) # Se agregan los reservados para no hacer reglas

### reservados

def t_IF(t):
    r'if[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_ELSE(t):
    r'else[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_WHILE(t):
    r'while[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_VOID(t):
    r'void[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_RETURN(t):
    r'return[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t
    
def t_INT(t):
    r'int[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_COMMENT(t):
    r'\/\*(\*+[^\/\*]|[^\*])*\*+\/'
    n_lines = len(t.value.split('\n')) - 1
    t.lexer.lineno += n_lines

def t_SPACE(t):
    r'\s'
    if t.value == '\n':
        t.lexer.lineno += 1

def t_ID(t):
    r'[A-Za-z]+[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

def t_NUM(t):
    r'[0-9]+[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t

# t_TAB = r'[ \t]+|\n+'
t_ENDFILE = r'\$'
t_PLUS = r'\+'
t_MINUS = r'-'
t_DIVIDE = r'/'
t_LESSOREQUAL = r'<='
t_LESS = r'<'
t_MOREOREQUAL = r'>='
t_MORE = r'>'
t_EQUALS = r'=='
t_DIFFERENT = r'!='
t_ASSIGN = r'='
t_SEMICOLON = r';'
t_OPENPAR = r'\('
t_CLOSEPAR = r'\)'
t_OPENBRACKSQ = r'\['
t_CLOSEBRACKSQ = r'\]'
t_OPENBRACK = r'\{'
t_CLOSEBRACK = r'\}'
t_COMMA = r','
t_MULTIPLY = r'\*'
#t_COMMENT = r'/\*([^*]|[\n]|(\*+([^*/]|[\n])))*\*+/'
#t_ignore = " \n"

def t_error(t):
  print('Error de tokens en línea %d:' % (t.lexer.lineno))
  t.lexer.skip()

# lex function
lexer = lex.lex()

# re-introducir variables globales
def globales(prog, pos, long):
  globalTypes.globales(prog, pos, long, lexer)

# funcion de getToken
def getToken(imprime = True):
    # lexer con lex (la herramienta)
    # lexer = lex.lex()
    # lexer.input(programa)
    # while True:
    #     tok = lexer.token()
    #     if not tok:
    #         break
    #     token = tok.value
    #     tokenString = tok.type
    #     if tokenString != "TAB":
    #         print(token, " = " , tokenString)

    tok = lexer.token()
    token = tok.value
    tokenString = tok.type

    if imprime:
        print(token, " = " , tokenString)
    return (token, tokenString)
