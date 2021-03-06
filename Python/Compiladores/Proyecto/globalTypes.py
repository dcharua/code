from enum import Enum


class TokenType(Enum):
    ID = 'id'
    NUM = 'num'
    PLUS = '+'
    MINUS = '-'
    MULT = '*'
    DIV = '/'
    LESSER = '<'
    LESSEREQ = '<='
    GREATER = '>'
    GREATEREQ = '>='
    EQ = '=='
    NOTEQ = '!='
    ASSIGN = '='
    SEMICOLON = ';'
    COMMA = ','
    OPENPAR = '('
    CLOSEPAR = ')'
    OPENBRACKET = '{'
    CLOSEBRACKET = '}'
    OPENBRACE = '['
    CLOSEBRACE = ']'
    ELSE = 'else'
    IF = 'if'
    WHILE = 'while'
    INT = 'int'
    RETURN = 'return'
    VOID = 'void'
    ENDFILE = '$'
