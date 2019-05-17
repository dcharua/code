import globalTypes
from globalTypes import *
from parser import *
import yacc


import globals


def semantica(tree, imprime=True):
    tabla(tree, imprime)


def build_table(node, table, returns=False):
    if node[0] is 'function_declaration':
        addFunction(node, table)
        if node[1] is 'int':
            build_table(node[3], table['content'][node[2]][3], True)
            build_table(node[4], table['content'][node[2]][3], True)
        else:
            build_table(node[3], table['content'][node[2]][3], False)
            build_table(node[4], table['content'][node[2]][3], False)
        return None

    elif node[0] is 'variable_declaration':
        addVariable(node, table)
        return None

    elif node[0] is 'number':
        return ['variable', 'int']

    elif node[0] is 'var':
        variable = getID(table, node[1])
        child = None
        if isDeclared(variable):
            if not isVariable(variable):
                return ['variable', variable[2]]
            return [variable[1], variable[2]]
        return ['variable', 'int']

    elif node[0] is 'function_call':
        fun = getID(table, node[1])
        content = []
        for child in node[2][1:]:
            content.append(build_table(child, table, returns))
        if isDeclared(fun):
            if not isFunction(fun):
                return [fun[1], fun[2]]
            return ['variable', fun[1]]
        return ['variable', 'int']

    elif node[0] in ['==', '!=', '<=', '<', '>=', '>', '+', '-', '*', '/', '=']:
        child = build_table(node[1], table, returns)
        intOp(child)
        child = build_table(node[2], table, returns)
        intOp(child)
        return ['variable', 'int']

    elif node[0] is 'iteration_stmt':
        child = build_table(node[2], table, returns)
        intOp(child)
        build_table(node[3], table, returns)
        return None

    elif node[0] is 'selection_stmt':
        child = build_table(node[2], table, returns)
        intOp(child)
        build_table(node[3], table, returns)
        if len(node) > 6:
            build_table(node[4], table, returns)
        return None

    elif node[0] is 'return_stmt':
        if len(node) > 3:
            child = build_table(node[1], table, returns)
            intOp(child)
        returnCheck(node, returns)
        return None

    else:
        for child in node[1:]:
            if type(child) is list:
                build_table(child, table, returns)

    return None


def tabla(tree, imprime=True):
    table = {'content': { 'input': ['function', 'int', [], {'content': {}}], 'output': ['function', 'void', [['variable', 'int']], {'content': {}}]},'scope': None}
    table['content']['input'][3]['scope'] = table
    table['content']['output'][3]['scope'] = table
    build_table(tree, table, False)
    if imprime:
        print_table(table)
    return table


def addVariable(node, table):
    variable_id = node[3]
    wasDefined(table, variable_id)
    table['content'][variable_id] = ['variable', node[1], node[2]]


def addFunction(node, table):
    function_id = node[2]
    wasDefined(table, function_id)
    table['content'][function_id] = [ 'function', node[1], [], { 'content': {}, 'scope': table }]


def getID(table, id):
    if id in table['content']:
        return table['content'][id]
    if table['scope'] != None:
        return getID(table['scope'], id)
    return None


def isDeclared(symbol):
    if symbol is None:
        error('ERROR variable NOT declared')
        return False
    return True


def wasDefined(table, id):
    if id in table['content']:
        error('ERROR variable already declared')


def isVariable(variable):
    if variable[0] != 'variable':
        error('ERROR is not a variable')
        return False
    return True


def isFunction(function):
    if function[0] != 'function':
        error('ERROR in function call')
        return False
    return True

def returnCheck(node, returns):
    if returns and len(node) is 3:
        error('ERROR function most return an int')
    if not returns and len(node) > 3:
        error('ERROR function return is a VOID')


def intOp(variable):
    if str(variable[1]) != 'int':
        error('ERROR in operation with Int')


def error(message):
    print(message)


def print_table(table, level=0):
    for symbol, entry in table['content'].items():
        print('  ' * level, symbol + ':', entry[:3])
        if entry[0] == 'function':
            print_table(entry[3], level + 1)
