# Daniel Charua - A01017419

import lex
import re
import globals
from globalTypes import *


def getToken(imprime=True):
    token = lexer.token()
    if imprime:
        print(token.type, token.value)
    if token.type == 'ENDFILE':
        return (TokenType.ENDFILE, token.value)
    return (token.type, token.value)


def globales(prog, pos, long):
    globals._globales(prog, pos, long, lexer)

# ERROR FUNCTION


def t_error(t):
    print('TOKEN ERROR in line %d:' % (t.lexer.lineno))
    count = 1
    while re.match(r'[A-Za-z0-9]', t.value[count]):
        count += 1
    t.lexer.skip(count)


tokens = []
for token in TokenType:
    tokens.append(token.name)

# LEXER RULES


def t_ELSE(t):
    r'else[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


def t_INT(t):
    r'int[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


def t_IF(t):
    r'if[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


def t_WHITESPACE(t):
    r'\s'
    if t.value == '\n':
        t.lexer.lineno += 1


def t_COMMENT(t):
    r'\/\*(\*+[^\/\*]|[^\*])*\*+\/'
    n_lines = len(t.value.split('\n')) - 1
    t.lexer.lineno += n_lines


def t_WHILE(t):
    r'while[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


def t_RETURN(t):
    r'return[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


def t_VOID(t):
    r'void[^A-Za-z0-9]'
    t.value = t.value[:-1]
    t.lexer.lexpos -= 1
    return t


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


t_PLUS = r'\+'
t_MINUS = r'\-'
t_MULT = r'\*'
t_DIV = r'\/'
t_LESSER = r'\<'
t_LESSEREQ = r'\<\='
t_GREATER = r'\>'
t_GREATEREQ = r'\>\='
t_EQ = r'\=\='
t_NOTEQ = r'\!\='
t_ASSIGN = r'\='
t_SEMICOLON = r'\;'
t_COMMA = r'\,'
t_OPENPAR = r'\('
t_CLOSEPAR = r'\)'
t_OPENBRACKET = r'\['
t_CLOSEBRACKET = r'\]'
t_OPENBRACE = r'\{'
t_CLOSEBRACE = r'\}'
t_ENDFILE = r'\$'


lexer = lex.lex()
