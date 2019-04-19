# Mauricio Rico
# global types

from enum import Enum

class TokenType(Enum):
    ID = 'id'
    NUM = 'num'
    PLUS = 'plus'
    MINUS = 'minus'
    ELSE = 'else'
    IF = 'if'
    WHILE = 'while'
    INT = 'int'
    RETURN = 'return'
    VOID = 'void'
    MULTIPLY = 'multiply'
    DIVIDE = 'divide'
    LESS = 'less'
    LESSOREQUAL = 'lessorequal'
    MORE = 'more'
    MOREOREQUAL = 'moreorequal'
    EQUALS = 'equals'
    DIFFERENT = 'different'
    ASSIGN = 'assign'
    SEMICOLON = 'semicolon'
    COMMA = 'comma'
    OPENPAR = 'openpar'
    CLOSEPAR = 'closepar'
    OPENBRACK = 'openbrack'
    CLOSEBRACK = 'closebrack'
    OPENBRACKSQ = 'openbracksq'
    CLOSEBRACKSQ = 'closebracksq'
    ENDFILE = '$'
    SPACE = 'space'
    COMMENT = 'comment'

# funcion para los globales
def globales(prog, pos, long, lexer):
    global programa
    global posicion
    global progLong
    programa = prog
    posicion = pos
    progLong = long
    lexer.input(programa)

# reserved = {
#     'if' : 'IF',
#     'else' : 'ELSE',
#     'while' : 'WHILE',
#     'void' : 'VOID',
#     'return': 'RETURN',
#     'int': 'INT'
# }
#
# tokens = [
#     'PLUS',
#     'MINUS',
#     'ENDFILE',
#     'ID',
#     'NUM',
#     'COMMENT',
#     'OPENPAR',
#     'CLOSEPAR',
#     'OPENBRACKSQ',
#     'CLOSEBRACKSQ',
#     'DIVIDE',
#     'LESSOREQUAL',
#     'LESS',
#     'MOREOREQUAL',
#     'MORE',
#     'EQUALS',
#     'DIFFERENT',
#     'ASSIGN',
#     'SEMICOLON',
#     'COMMA',
#     'MULTIPLY',
#     'OPENBRACK',
#     'CLOSEBRACK',
# ] + list(reserved.values())
#
# # t_TAB = r'[ \t]+|\n+'
# t_ENDFILE = r'\$'
# t_PLUS = r'\+'
# t_MINUS = r'-'
# t_DIVIDE = r'/'
# t_LESSOREQUAL = r'<='
# t_LESS = r'<'
# t_MOREOREQUAL = r'>='
# t_MORE = r'>'
# t_EQUALS = r'=='
# t_DIFFERENT = r'!='
# t_ASSIGN = r'='
# t_SEMICOLON = r';'
# t_OPENPAR = r'\('
# t_CLOSEPAR = r'\)'
# t_OPENBRACKSQ = r'\['
# t_CLOSEBRACKSQ = r'\]'
# t_OPENBRACK = r'\{'
# t_CLOSEBRACK = r'\}'
# t_COMMA = r','
# t_MULTIPLY = r'\*'
# t_COMMENT = r'/\*([^*]|[\n]|(\*+([^*/]|[\n])))*\*+/'
# t_ignore = " \n"
#
# def t_ID(t):
#      r'[a-zA-Z][a-zA-Z]*'
#      t.type = reserved.get(t.value,'ID')    # Check for reserved words
#      return t
#
# def t_NUM(t):
#     r'\d+'
#     t.value = int(t.value)
#     return t
#
# def t_error(t):
#     print('caracter incorrecto!')
#     t.lexer.skip(1)
