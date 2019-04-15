# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
from globalTypes import *
from lexer import *
string = '3*(4+5)'



#def parser(token, tokenString)

import functools as fn


class Node:

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def setHead(self, data):
        self.data = data

    def setRight(self, data):
        self.right = Node(data)

    def setLeft(self, data):
        self.left = Node(data)

    def __str__(self):
        return(f'\n\t head {self.data} \n right {self.right} \t left {self.left}')
    
    
 
def exp():
    temp = Node(None)
    newTemp = Node(None)
    temp = term()
    if token == '+' or token == '-':
        newTemp.setHead(token)
        match(token)
        newTemp.setLeft(temp)
        newTemp.setRight(term())
        temp = newTemp
    return temp

def term():
    temp= Node(None) 
    newTemp = Node(None)
    temp = factor()
    if token == '*':
        newTemp.setHead(token)
        match(token)
        newTemp.setLeft(temp)
        newTemp.setRight(factor())
        temp = newTemp
    return temp

def factor():
    temp = Node(None)
    newTemp = Node(None)
    if token == '(':
        match(token)
        newTemp.setHead(exp())
        if token == ')':
            match(token)
    elif token.isnumeric():
        newTemp.setHead(token)
        match(token)
    else:
        print("Error")
    temp = newTemp
    return temp


def match(c):
    global token
    global posicion
    if token == c:
        posicion += 1
        if posicion == len(string):
            token = '$'
        else: 
            token = string[posicion]

def main(): 
    global posicion
    global token
    posicion = 0
    token = string[0]
    node = exp()
    print(node)
     
    

main()
    


# token, tokenString = getToken()
# while (token != TokenType.ENDFILE):
#     token, tokenString= getToken()
#     parser(token, tokenString)


