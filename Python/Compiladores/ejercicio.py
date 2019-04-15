import re 
string = '3*(4+3'

def E():
    if T():
        if token == '+':
            match(token)
            if posicion != len(string):
                E()
            else:
                return False
        return True
    else:
        return False;        

def T():
    if token.isnumeric():
        match(token)
        if token == '*':
            match(token)
            T()
        return True
    
    elif token == '(':
        match(token)
        if E():
            if posicion != len(string) and token == ')':
                return True
            else:
                return False
    else:
        return False

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
    if E():
        print('true')
    else:
        print('false')
    

main()
    