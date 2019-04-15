# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
import globalTypes
from lexer import *


def parser(imprime = True):
    print(globalTypes.programa)
    global tokenString
    global token
    token, tokenString = getToken()
    node = program()
    node.printTree(0)

class Node:
    def __init__(self, root):
        self.root = root
        self.children = []

    def addChild(self,child):
        self.children.append(child)

    #Print the tree, this function receive a start identation
    def printTree(self,indentation):
        print("\t" * indentation,self.root)
        for child in self.children:
            child.printTree(indentation+1)


#1	program -> declaration-list
def program():
    return declaration_list()

#2	declaration-list -> declaration {declaration} 
def declaration_list():
    node = Node("declaration_list")
    child = declaration()
    if child is not None:
        node.addChild(child)
    else:
        error('Error')
    while globalTypes.posicion < globalTypes.progLong-1:
        child = declaration()
        if child is not None:
            node.addChild(child)
        else:
            error('Error')
    return node

#3	declaration -> type-specifier ID (var-declaration | fun-declaration)
def declaration():
    
    node = Node("declaration")
    child = type_specifier()
   
    if child is not None:
        node.addChild(child)
        temp = Node(tokenString)
        if match_type('ID'):
            node.addChild(temp)

            child = var_declaration()
            if child is not None:
                node.addChild(child)
                return node
   
            child = fun_declaration()
            if child is not None:
                node.addChild(child)
                return node
    return None

#4	 var-declaration -> type-specifier (; |  [NUM]);
def var_declaration():
    node = Node("var_declaration")
    child = type_specifier()


    if match(';'):
        return node
    elif match('['):
        node.addChild(Node('['))
        temp = Node(tokenString)
        if match_type("INT"):          
            node.addChild(temp)
        else:
            error('Not a number')
        if match(']'):
            node.addChild(Node(']'))
            if match(';'): 
                node.addChild(Node(';'))
                return node
        else:
            error('No closing ]')         
    return None

#5	type-specifier -> int | void
def type_specifier():
    node = Node("type-specifier")
    string = tokenString
    if match('int') or match('void'):
        node.addChild(Node(string))
        return node
    else:
        return None
        

#6 fun-declaration-> ( params ) compound-stmt
def fun_declaration():
    node = Node("fun-declaration")
    child = type_specifier()
    if match('('):
        node.addChild(Node('('))
        child = params()
        if child is not None:
            node.addChild(child)
            if match(')'):
                child = compound_stmt()
                if child is not None:
                    node.addChild(child)
                    return node
    return None

#7 params-> param-list | void
def params():
   
    node = param_list()
    if node is not None:
        return node
    else: 
        if match('void'):
            node = (Node('void'))
            return node
    return None


#8 param-list -> param {, param}
def param_list():
    node = Node("param-list")
    child = param()
    if child is not None:
        node.addChild(child)
        while match(','):
            child = param()
            if child is not None:
                node.addChild(child)
            else:
                error('no param after comma')
        return node
    return None


#9 param -> type-specifier [ID | ID [ ] ]
def param():
    node = Node("param")
    child = type_specifier()
    if child is not None:
        node.addChild(child)
        temp = Node(tokenString)
        if match_type('ID'):
            node.addChild(temp)
            if match('['):
                node.addChild(Node('['))
                temp = Node(tokenString)
                if match_type("INT"):          
                    node.addChild(temp)
                else:
                    error('Not a number')
                if match(']'):
                    node.addChild(Node(']'))
                    return node
                else:
                    error('No closing ]')
            else:
                return node                
    return None

#10 compount-stmt -> empty { local-declarations statement-list }
def compound_stmt():
    node = Node("compount-stmt")

    if match('{'):
        node.addChild(Node('{'))
        child = local_declarations()
        if child is not None:
            node.addChild(child)
        child = statement_list()
        if child is not None:
            node.addChild(child)
        if match('}'):
            node.addChild(Node('}'))
            return node
        return node

    return None

#11 local-declarations -> empty {var-declaration}
def local_declarations():
    node = Node("local-declaration")
    child = var_declaration()
    if child is None:
        node.addChild(Node('empty'))
    while child is not None:
        node.addChild(child)
        child = var_declaration()
    return node
   

#12 statement-list -> empty {statement} 
def statement_list():
    node = Node("statement-list")
    child = statement()
    if child is None:
        node.addChild(Node('empty'))
    while child is not None:
        node.addChild(child)
        child = statement()
    return node

#13 statement -> expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt
def statement():
    node = Node("statement-list")
    child = expression_stmt()
    if child is not None:
        node.addChild(child)
        return node

    child = compound_stmt()
    if child is not None:
        node.addChild(child)
        return node
    
    child = selection_stmt()
    if child is not None:
        node.addChild(child)
        return node

    child = iteration_stmt()
    if child is not None:
        node.addChild(child)
        return node

    child = return_stmt()
    if child is not None:
        node.addChild(child)
        return node
    
    return None

#14 expression-stmt -> expression ; |  ;
def expression_stmt():
    node = Node("expression-stmt")
    child = expression()
    if child is not None:
        node.addChild(child)
        if match(';'):
            node.addChild(Node(';'))
            return node
    elif match(';'):
        node.addChild(Node(';'))
        return node
    return None

#15 selection-stmt ->  if ( expression ) statement | if ( expression ) statement else statement
def selection_stmt():
    node = Node("selection-stmt")
    if match('if'):
        node.addChild(Node('if'))
        if match('('):
            node.addChild(Node('('))
            child = expression()
            if child is not None:
                node.addChild(child)
                if match(')'):
                    node.addChild(Node(')'))
                    child = statement()
                    if child is not None:
                        node.addChild(child)
                        if match('else'):
                            node.addChild(Node('else'))
                            child = statement()
                            if child is not None:
                                node.addChild()
                                return node
                            else:
                                error('No statement after else')
                        return node
            else:
                error('No closing parentheses after if')
        else: 
            error('No opening parentheses after if')

    return None

#16 iteration-stmt -> while ( expression )  statement
def iteration_stmt():
    node = Node("iteration-stmt")
    if match('while'):
        node.addChild(Node('while'))
        if match('('):
            node.addChild(Node('('))
            child = expression()
            if child is not None:
                node.addChild(child)
                if match (')'):
                    node.addChild(Node('('))
                    child = statement()
                    if child is not None:
                        node.addChild(child)
                        return node
                    else:
                        error('No statment after while expression')
                else:
                    error('No opening parentheses after while expression')

            else:
                error("No expression after while")
        else:
            error('No opening parentheses after while')
    return None

#17 return-stmt -> return ;  |  return  expression ;
def return_stmt():
    node = Node("return-stmt")
    if match('return'):
        node.addChild(Node('return'))
        child = expression()
        if child is not None:
            node.addChild(child)
        if match(';'):
            node.addChild(Node(';'))
            return node
    return None

#18 expression -> var  =  expression | simple-expression
def expression():
    node = Node("expression")
    child = var()
    if child is not None:
        node.addChild(child)
        if match('='):
            node.addChild(Node('='))
            child = expression()
            if child is not None:
                node.addChild(child)
                return node

    child = simple_expression()
    if child is not None:
        node.addChild(child)
        return node

    return None

#19 var -> ID  |  ID [ expression ]
def var():
    node = Node("var")
    temp = Node(tokenString)
    if match_type('ID'):
        node.addChild(temp)
        if match('['):
            node.addChild(Node('['))
            temp = Node(tokenString)
            if match_type("INT"):          
                node.addChild(temp)
            else:
                error('Not a number')
            if match(']'):
                node.addChild(Node(']'))
                return node
            else:
                error('No closing ]')
        else:
            return node 
    return None


#20 simple-expression -> additive-expression [relop additive-expression]
def simple_expression():
    node = Node("simple-expression")
    child = additive_expression()
    if child is not None:
        node.addChild(child)
        child = relop()
        if child is not None:
            node.addChild(child)
            child = additive_expression()
            if child is not None:
                node.addChild(child)
                return node
        else:
            return node
    return None

#21 relop -> <= | < | > | >= | = | !=
def relop():
    node = Node("relop")
    if match('<='):
        node.addChild(Node('<='))
        return node
    if match('<'):
        node.addChild(Node('<'))
        return node
    if match('>'):
        node.addChild(Node('>'))
        return node
    if match('>='):
        node.addChild(Node('>='))
        return node
    if match('='):
        node.addChild(Node('='))
        return node
    if match('!='):
        node.addChild(Node('!='))
        return node
    return None


#22 additive-expression -> term {addop term}
def additive_expression():
    node = term()
    if node is not None:
        node.addChild(node)
        child = addop()
        while child is not None:
            node.addChild(child)
            child = term()
            if child is not None:
                child = addop()
            else:
                error("no term after +/- operation")    
        return node
    return None

#23 addop -> + | -
def addop():
    if match('+'):
        node= Node('+')
        return node
    if match('-'):
        node = Node('-')
        return node
    return None

#24 term -> factor {mulop factor}
def term():
    node = Node("term")
    child = factor()
    if child is not None:
        node.addChild(child)
        child = mulop()
        while child is not None:
            node.addChild(child)
            child = factor()
            if child is not None:
                child = mulop()
            else:
                error("no term after * / operation")   
        return node
    return None

#25 mulop -> * | /
def mulop():
    node = Node("mulop")
    if match('*'):
        node.addChild(Node('*'))
        return node
    if match('/'):
        node.addChild(Node('/'))
        return node
    return None

#26 factor -> ( expression ) | var | call | NUM
def factor():
    node = Node("factor")
    if match('('):
        node.addChild('(')
        child = expression()
        if child is not None:
            node.addChild(child)
            if match(')'):
                node.addChild(Node(')'))
                return node

    child = var()
    if child is not None:
        node.addChild(child)
        return node
    
    child = call()
    if child is not None:
        node.addChild(child)
        return node

    temp = Node(tokenString)
    if match_type('INT'):
        node.addChild(temp)
        return node
    
    return None

#27 call -> ID ( args )
def call():
    node = Node('call')
    temp = tokenString
    if match_type('ID'):
        node.addChild(temp)
        if match('('):
            node.addChild('(')
            child = args()
            if child is not None:
                node.addChild(child)
                if match(')'):
                    node.addChild(None(')'))
                    return node
    return None

#28 args -> arg-list | empty
def args():
    node = Node('args')
    child = arg_list()
    if child is not None:
        node.addChild(child)
    else: 
        node.addChild(Node('empty'))
    return node
#29 arg-list -> expression {, expression}
def arg_list():
    node = Node('arg-list')
    child = expression()
    if child is not None:
        node.addChild(child)
        while match(','):
            node.addChild(Node(','))
            child = expression()
            if child is not None:
                node.addChild(node)
            else:
                break
        return node
    return None


#Error function
def error(msg):
    print(f' {msg} in position {globalTypes.posicion}' )
    exit()


def match(c):
    global token, tokenString 
    if tokenString == c:
        token, tokenString = getToken()
        return True
    else:
        return False

def match_type(type):
    global token, tokenString 
    if token.value == type:
        token, tokenString = getToken()
        return True
    else:
        return False

