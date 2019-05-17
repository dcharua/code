# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
from enum import Enum
class TokenType(Enum):
    ENDFILE  = 'endfile'
    RESERVED = 'reserved'
    COMMENT  = 'comment'
    INT      = 'INT'
    ID       = 'ID'
    SPACE    = 'space'
    ERROR    = 'error'
    SPECIAL  = 'special'


def globales(prog, pos, long):
    global programa
    global posicion
    global progLong
    programa = prog
    posicion = pos
    progLong = long