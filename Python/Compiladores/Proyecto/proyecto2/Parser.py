#dDaniel Charua - A01017419

import yacc
import globals
from lexer import *
from globalTypes import *

# YACC RULES

#1	program -> declaration-list
def p_program(p):
  'program : declaration_list ENDFILE'
  p[0] = p[1]


#2	declaration-list -> declaration {declaration} 
def p_declaration_list_rec(p):
  'declaration_list : declaration_list declaration'
  result = ['declaration_list']
  if p[1][0] == 'declaration_list':
    for i in range(len(p[1])):
      if i != 0:
        result.append(p[1][i])
  else:
    result.append(p[1])
  result.append(p[2])
  p[0] = result

def p_declaration_list_bas(p):
  'declaration_list : declaration'
  p[0] = p[1]


#3	declaration -> type-specifier ID (var-declaration | fun-declaration)
def p_declaration_fun(p):
  'declaration : fun_declaration'
  p[0] = p[1]

def p_declaration_var(p):
  'declaration : var_declaration'
  p[0] = p[1]


#4	 var-declaration -> type-specifier (; |  [NUM]);
def p_var_declaration_arr(p):
  'var_declaration : type_specifier ID LEFTBRACKET NUM RIGHTBRACKET SEMICOLON'
  p[0] = ['variable', p[1], p[2], p[4]]

def p_var_declaration_n_arr(p):
  'var_declaration : type_specifier ID SEMICOLON'
  p[0] = ['variable', p[1], p[2]]


#5	type-specifier -> int | void
def p_type_specifier(p):
  '''type_specifier : INT 
  | VOID'''
  p[0] = p[1]


#6 fun-declaration-> ( params ) compound-stmt
def p_fun_declaration(p):
  'fun_declaration : type_specifier ID LEFTPAR params RIGHTPAR compound_stmt'
  p[0] = ['function', p[1], p[2], p[4], p[6]]


#7 params-> param-list | void
def p_params(p):
  '''params : param_list
  | VOID'''
  p[0] = p[1]


#8 param-list -> param {, param}
def p_param_list_rec(p):
  'param_list : param_list COMMA param'
  result = ['param_list']
  if p[1][0] == 'param_list':
    for i in range(len(p[1])):
      if i != 0:
        result.append(p[1][i])
  else:
    result.append(p[1])
  result.append(p[3])
  p[0] = result

def p_param_list_bas(p):
  'param_list : param'
  p[0] = p[1]


#9 param -> type-specifier [ID | ID [ ] ]
def p_param_n_arr(p):
  'param : type_specifier ID'
  p[0] = ['param', p[1], p[2]]

def p_param_arr(p):
  'param : type_specifier ID LEFTBRACKET RIGHTBRACKET'
  p[0] = ['param', p[1], p[2]]


#10 compount-stmt -> empty { local-declarations statement-list }
def p_compound_stmt(p):
  'compound_stmt : LEFTBRACE local_declarations statement_list RIGHTBRACE'
  p[0] = ['compound_stmt', p[2], p[3]]


#11 local-declarations -> empty {var-declaration}
def p_local_declarations_rec(p):
  'local_declarations : local_declarations var_declaration'
  result = ['local_declarations']
  for i in range(len(p[1])):
    if i != 0:
      result.append(p[1][i])
  result.append(p[2])
  p[0] = result

def p_local_declarations_bas(p):
  'local_declarations :'
  p[0] = ['local_declarations']


#12 statement-list -> empty {statement} 
def p_statement_list_rec(p):
  'statement_list : statement_list statement'
  result = ['statement_list']
  for i in range(len(p[1])):
    if i != 0:
      result.append(p[1][i])
  if p[2] != None:
    result.append(p[2])
  p[0] = result

def p_statement_list_bas(p):
  'statement_list :'
  p[0] = ['statement_list']


#13 statement -> expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt
def p_statement(p):
  '''statement : compound_stmt
  | expression_stmt
  | selection_stmt
  | iteration_stmt
  | return_stmt'''
  if p[1] != None:
    p[0] = p[1]


#14 expression-stmt -> expression ; |  ;
def p_expression_stmt(p):
  '''expression_stmt : expression SEMICOLON
  | SEMICOLON'''
  if p[1] != ';':
    p[0] = p[1]


#15 selection-stmt ->  if ( expression ) statement | if ( expression ) statement else statement
def p_selection_stmt_n_el(p):
  'selection_stmt : IF LEFTPAR expression RIGHTPAR statement'
  p[0] = ['selection_stmt', p[3], p[5]]

def p_selection_stmt_el(p):
  'selection_stmt : IF LEFTPAR expression RIGHTPAR statement ELSE statement'
  p[0] = ['selection_stmt', p[3], p[5], p[7]]


#16 iteration-stmt -> while ( expression )  statement
def p_iteration_stmt(p):
  'iteration_stmt : WHILE LEFTPAR expression RIGHTPAR statement'
  p[0] = ['iteration_stmt', p[3], p[5]]


#17 return-stmt -> return ;  |  return  expression ;
def p_return_stmt_n_exp(p):
  'return_stmt : RETURN SEMICOLON'
  p[0] = ['return_stmt']

def p_return_stmt_exp(p):
  'return_stmt : RETURN expression SEMICOLON'
  p[0] = ['return_stmt', p[2]]


#18 expression -> var  =  expression | simple-expression
#19 var -> ID  |  ID [ expression ]
def p_expression_rec(p):
  'expression : var ASSIGN expression'
  result = ['=']
  result.append(p[1])
  if p[3][0] == 'expression':
    for i in range(len(p[3])):
      if i != 0:
        result.append(p[3][i])
  else:
    result.append(p[3])
  p[0] = result

def p_expression_bas(p):
  'expression : simple_expression'
  p[0] = p[1]


#20 simple-expression -> additive-expression [relop additive-expression]
def p_simple_expression_relop(p):
  'simple_expression : additive_expression relop additive_expression'
  p[0] = [p[2], p[1], p[3]]

def p_simple_expression_n_relop(p):
  'simple_expression : additive_expression'
  p[0] = p[1]


#21 relop -> <= | < | > | >= | = | !=
def p_relop(p):
  '''relop : LESSER
  | LESSEREQ
  | GREATER
  | GREATEREQ
  | EQ
  | NOTEQ'''
  p[0] = p[1]


#22 additive-expression -> term {addop term}
def p_additive_expression_addop(p):
  'additive_expression : additive_expression addop term'
  p[0] = [p[2], p[1], p[3]]

def p_additive_expression_n_addop(p):
  'additive_expression : term'
  p[0] = p[1]


#23 addop -> + | -
def p_addop(p):
  '''addop : PLUS
  | MINUS'''
  p[0] = p[1]


#24 term -> factor {mulop factor}
def p_term_mulop(p):
  'term : term mulop factor'
  p[0] = [p[2], p[1], p[3]]


#25 mulop -> * | /
def p_term_n_mulop(p):
  'term : factor'
  p[0] = p[1]

def p_mulop(p):
  '''mulop : MULT
  | DIV'''
  p[0] = p[1]


#26 factor -> ( expression ) | var | call | NUM
def p_factor_var(p):
  'factor : var'
  p[0] = p[1]

def p_factor_call(p):
  'factor : call'
  p[0] = p[1]

def p_factor_num(p):
  'factor : NUM'
  p[0] = p[1]

def p_factor_exp(p):
  'factor : LEFTPAR expression RIGHTPAR'
  p[0] = p[2]


#27 call -> ID ( args )
def p_call(p):
  'call : ID LEFTPAR args RIGHTPAR'
  result = ['call', p[1]]
  if p[3] != None:
    result.append(p[3])
  p[0] = result

#28 args -> arg-list | empty
def p_args_list(p):
  'args : arg_list'
  p[0] = p[1]

def p_args_emp(p):
  'args :'

#29 arg-list -> expression {, expression}
def p_arg_list_rec(p):
  'arg_list : arg_list COMMA expression'
  result = ['arg_list']
  if p[1][0] == 'arg_list':
    for i in range(len(p[1])):
      if i != 0:
        result.append(p[1][i])
  else:
    result.append(p[1])
  result.append(p[3])
  p[0] = result

def p_arg_list_bas(p):
  'arg_list : expression'
  p[0] = p[1]

def p_var_n_exp(p):
  'var : ID'
  p[0] = p[1]

def p_var_exp(p):
  'var : ID LEFTBRACKET expression RIGHTBRACKET'
  p[0] = ['var', p[1], p[3]]


#Error function
def p_error(p):
  print('PARSER ERROR found in char %s line %d:' % (TokenType[p.type].value, p.lineno))
  _parser.restart()


#Function to print Tree
def printAST(node, level=0):
  print('  ' * level, node[0])
  for child in node[1:]:
    if type(child) == list:
      printAST(child, level + 1)
    else:
      print('  ' * (level + 1), child)


def parser(imprime=True):
  AST = _parser.parse(lexer=lexer)
  if imprime:
    printAST(AST)
  return AST

_parser = yacc.yacc()