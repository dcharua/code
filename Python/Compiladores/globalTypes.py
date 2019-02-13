# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
from enum import Enum
class TokenType(Enum):
    ENDFILE  = 'endfile '
    RESERVED = 'reserved'
    COMMENT  = 'comment '
    INT      = 'int     '
    ID       = 'id      '
    SPACE    = 'space   '
    ERROR    = 'error   '

