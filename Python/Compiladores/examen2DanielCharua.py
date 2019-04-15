# Parcial 2 - Daniel Charua - A01017419 - 18/10/18

string = '(c,(c,(3)),(c))'
 
def A():
    if token == '3':
        match(token)
        return True
    elif token == 'c':
        match(token)
        return True
    elif token == '(':
        match(token)
        if B():
            if token == ')':
                match(token)
                return True
    return False

def B():
    if A():
        if token == ',':
            match(token)
            if B():
                return True
            else:
                return False
        return True


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
    string = input('Enter the string:')
    token = string[0]
    print(A())

main()