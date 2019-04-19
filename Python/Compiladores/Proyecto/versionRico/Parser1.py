# Mauricio Rico
# Parser

import globalTypes
from globalTypes import *
from lexer import *
# import ply.lex as lex # para lexer
import yacc # para yacc

# # funcion para los globales
# def globales(prog, pos, long):
#     global programa
#     global posicion
#     global progLong
#     programa = prog
#     posicion = pos
#     progLong = long

############# EMPIEZAN LAS GRAMATICAS EN BNF GRACIAS AL YACC

#### 1
def p_program(p):
    'program : declaration_list ENDFILE'
    p[0] = ['program', p[1]]

#### 2a
def p_declaration_list_a(p):
    'declaration_list : declaration_list declaration'
    temp = ['declaration_list']
    if p[1][0] == 'declaration_list':
        for i in range(len(p[1])):
            if i != 0:
                temp.append(p[1][i])
    else:
        temp.append(p[1])
    temp.append(p[2])
    p[0] = temp

#### 2b
def p_declaration_list_b(p):
    'declaration_list : declaration'
    p[0] = ['declaration_list', p[1]]

#### 3a
def p_declaration_a(p):
    'declaration : fun_declaration'
    p[0] = ['declaration', p[1]]

#### 3b
def p_declaration_b(p):
    'declaration : var_declaration'
    p[0] = ['declaration', p[1]]

#### 4a
def p_var_declaration_a(p):
    'var_declaration : type_specifier ID SEMICOLON'
    p[0] = ['var_declaration', p[1], p[2]]

#### 4b
def p_var_declaration_b(p):
    'var_declaration : type_specifier OPENBRACKSQ ID NUM CLOSEBRACKSQ SEMICOLON'
    p[0] = ['var_declaration', p[1], p[3], p[4]]

#### 5
def p_type_specifier(p):
    '''type_specifier : INT
                      | VOID'''
    p[0] = ['type_specifier', p[1]]

#### 6
def p_fun_declaration(p):
    'fun_declaration : type_specifier ID OPENPAR params CLOSEPAR compound_stmt'
    p[0] = ['fun_declaration', p[1], p[2], p[4], p[6]]

#### 7
def p_params(p):
    '''params : param_list
              | VOID'''
    p[0] = ['params', p[1]]

#### 8a
def p_param_list_a(p):
    'param_list : param_list COMMA param'
    temp = ['param_list']
    if p[1][0] == 'param_list':
        for i in range(len(p[1])):
            if i != 0:
                temp.append(p[1][i])
    else:
        temp.append(p[1])
    temp.append(p[3])
    p[0] = temp

#### 8b
def p_param_list_b(p):
    'param_list : param'
    p[0] = ['param_list', p[1]]

#### 9a
def p_param_a(p):
    'param : type_specifier ID'
    p[0] = ['param', p[1], p[2]]

#### 9b
def p_param_b(p):
    'param : type_specifier ID OPENBRACKSQ CLOSEBRACKSQ'
    p[0] = ['param', p[1], p[2]]

#### 10
def p_compound_stmt(p):
    'compound_stmt : OPENBRACK local_declarations statement_list CLOSEBRACK'
    p[0] = ['compound_stmt', p[2], p[3]]

#### 11a
def p_local_declarations_a(p):
    'local_declarations : local_declarations var_declaration'
    temp = ['local_declarations']
    for i in range(len(p[1])):
        if i != 0:
            temp.append(p[1][i])
    temp.append(p[2])
    p[0] = temp

#### 11b
def p_local_declarations_b(p):
    'local_declarations : empty'
    p[0] = ['local_declarations']

#### 12a
def p_statement_list_a(p):
    'statement_list : statement_list statement'
    temp = ['statement_list']
    for i in range(len(p[1])):
        if i != 0:
            temp.append(p[1][i])
    if p[2] != None:
        temp.append(p[2])
    p[0] = temp

#### 12b
def p_statement_list_b(p):
    'statement_list : empty'
    p[0] = ['statement_list']

#### 13
def p_statement(p):
    '''statement : expression_stmt
                 | compound_stmt
                 | selection_stmt
                 | iteration_stmt
                 | return_stmt'''
    # if p[1] != None:
    p[0] = ['statement', p[1]]

#### 14
def p_expression_stmt(p):
    '''expression_stmt : expression SEMICOLON
                       | SEMICOLON'''
    if p[1] != ';':
        p[0] = ['expression_stmt', p[1]]

#### 15a
def p_selection_stmt_a(p):
    'selection_stmt : IF OPENPAR expression CLOSEPAR statement'
    p[0] = ['selection_stmt', p[3], p[5]]

#### 15b
def p_selection_stmt_b(p):
    'selection_stmt : IF OPENPAR expression CLOSEPAR statement ELSE statement'
    p[0] = ['selection_stmt', p[3], p[5], p[7]]

#### 16
def p_iteration_stmt(p):
    'iteration_stmt : WHILE OPENPAR expression CLOSEPAR statement'
    p[0] = ['iteration_stmt', p[3], p[5]]

### 17a
def p_return_stmt_a(p):
    'return_stmt : RETURN SEMICOLON'
    p[0] = ['return_stmt']

### 17b
def p_return_stmt_b(p):
    'return_stmt : RETURN expression SEMICOLON'
    p[0] = ['return_stmt', p[2]]

#### 18a
def p_expression_a(p):
    'expression : var ASSIGN expression'
    temp = ['=']
    temp.append(p[1])
    if p[3][0] == 'expression':
        for i in range(len(p[3])):
            if i != 0:
                temp.append(p[3][i])
    else:
        temp.append(p[3])
    p[0] = temp

#### 18b
def p_expression_b(p):
    'expression : simple_expression'
    p[0] = ['expression', p[1]]

#### 19a
def p_var_a(p):
    'var : ID'
    p[0] = ['var', p[1]]

#### 19b
def p_var_b(p):
    'var : ID OPENBRACKSQ expression CLOSEBRACKSQ'
    p[0] = ['var', p[1], p[3]]

#### 20a
def p_simple_expression_a(p):
    'simple_expression : additive_expression relop additive_expression'
    p[0] = ['simple_expression', p[2], p[1], p[3]]

#### 20b
def p_simple_expression_b(p):
    'simple_expression : additive_expression'
    p[0] = ['simple_expression', p[1]]

#### 21
def p_relop(p):
    '''relop : LESSOREQUAL
             | LESS
             | MORE
             | MOREOREQUAL
             | EQUALS
             | DIFFERENT'''
    p[0] = ['relop', p[1]]

#### 22a ########################################################
def p_additive_expression_a(p):
    'additive_expression : additive_expression addop term'
    p[0] = ['additive_expression', p[2], p[1], p[3]]

#### 22b
def p_additive_expression_b(p):
    'additive_expression : term'
    p[0] = ['additive_expression', p[1]]

#### 23
def p_addop(p):
    '''addop : PLUS
             | MINUS'''
    p[0] = ['addop', p[1]]

#### 24a
def p_term_a(p):
    'term : term mulop factor'
    p[0] = ['term', p[2], p[1], p[3]]

#### 24b
def p_term_b(p):
    'term : factor'
    p[0] = ['term', p[1]]

#### 25
def p_mulop(p):
    '''mulop : MULTIPLY
             | DIVIDE'''
    p[0] = ['mulop', p[1]]

#### 26a
def p_factor_a(p):
    'factor : OPENPAR expression CLOSEPAR'
    p[0] = ['factor', p[2]]

#### 26b
def p_factor_b(p):
    'factor : var'
    p[0] = ['factor', p[1]]

#### 26c
def p_factor_c(p):
    'factor : call'
    p[0] = ['factor', p[1]]

#### 26b
def p_factor_d(p):
    'factor : NUM'
    p[0] = ['factor', p[1]]

#### 27
def p_call(p):
    'call : ID OPENPAR args CLOSEPAR'
    temp = ['call', p[1]]
    if p[3] != None:
        temp.append(p[3])
    p[0] = temp

#### 28a
def p_args_a(p):
    'args : arg_list'
    p[0] = ['args', p[1]]

#### 28b
def p_args_b(p):
    'args : empty'
    p[0] = ['args']

#### 29a
def p_arg_list_a(p):
    'arg_list : arg_list COMMA expression'
    temp = ['arg_list']
    if p[1][0] == 'arg_list':
        for i in range(len(p[1])):
            if i != 0:
                temp.append(p[1][i])
    else:
        temp.append(p[1])
    temp.append(p[3])
    p[0] = temp

#### 29b
def p_arg_list_b(p):
    'arg_list : expression'
    p[0] = ['arg_list', p[1]]

#### para las producciones vacias
def p_empty(p):
    'empty :'
    pass

### errror
def p_error(p):
    print('Error en syntax de %s en la linea %d:' % (TokenType[p.type].value, p.lineno))
    _parser.restart()

# Build the parser
_parser = yacc.yacc()

# funcion para el parser general
def parser(imprime = True):
    # variables globales
    # global tokenString
    # global token
    #print(tokens) # test
    # se introduce el lex desde aqui para que no se reinicie cada vez que se llama
    # lexer = lex.lex()
    # lexer.input(programa) # programa de los globales
    # token, tokenString = getToken(True)
    # while token != '$':
    #     token, tokenString = getToken(True)

    temp = _parser.parse(lexer=lexer)
    print(temp)
