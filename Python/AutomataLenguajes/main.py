# Reconocimento de Tokens - Daniel Charua - A01017419 - 18/10/18
import argparse

class AFD:
    # constructor, to set variables read transitions table from text
    def __init__(self, filename):
        self.transitions = {}
        self.tokens = ""
        self.state = 'a'
        #read line by line in file
        lines = [line.rstrip('\n') for line in open(filename)]
        #first line is the final states
        self.final = lines[0].split()
        #every other line are the transition table
        lines = lines[1:]
        for line in lines:
            #split by space and if word space is found in transition switch it for a " "
            element = line.split()
            if element[1] == "space":
                element[1] = " "
            #stored as tuples in the key of a dict[(from, with)] = to, the value is the new state
            self.transitions[(element[0], element[1])] = element[2]

    #function to switch states
    def changeState(self, token):
        for key in self.transitions:
             if self.state in key[0] and token in key[1]:
                 return(self.transitions[key])
        #if transitions was not found return -1
        return '-1'

    #Function to read the file to be analysed
    def readFile(self, filename):
        file = open(filename, 'r')
        self.tokens = file.read().splitlines()
        file.close()

    #main function to loop all tokens
    def chechTokens(self):
        print('Token                                    Tipo\n-----------------------------------------------------------\n')
        token_holder = ""
        state_holder = ""
        #Loop every line in the file and add a space to send to final state
        for line in self.tokens:
            line += " "
            for i in range(len(line)):
                # if is not a final state
                if str(self.state) not in self.final:
                    # A state holder is used to determinate the previous state
                    # used for spacial states where new state is final state but previous must be known, EX: state 'e'
                    # done in order to simplify the Automata and remove unnecessary states
                    state_holder = self.state
                    self.state = self.changeState(line[i])
                    # if state is -1 token was not found print error and kill program
                    if self.state == '-1':
                        print("Token not supported %c, program terminated" %(line[i]))
                        quit()
                    # if is not spacial state or initial state add token
                    if self.state not in 'a e l':
                        token_holder += line[i]
                    #if its special state, write previous state, clean tokens,set state to special state, move back in loop
                    if self.state in 'e l':
                        self.writeConsole(token_holder, state_holder)
                        token_holder = ""
                        state_holder = self.state
                        token_holder += line[i]
                        i=i-1

                #if is final state print clean token ans set to initial state
                if str(self.state) in self.final:
                    self.writeConsole(token_holder, state_holder)
                    self.state = 'a'
                    token_holder = ""
            # end of line print to console for comment state and resetting state to initial state
            self.writeConsole(token_holder, state_holder)
            token_holder = ""
            self.state = 'a'

    #function to write to console depending on the final state
    def writeConsole(self, token, state):
        value = ""
        if token:
            if (state == 'b'):
                value = "Entero"
            if (state == 'c'):
                value = "Real"
            if (state == 'e'):
                if token == '=':
                    value = 'Asignación'
                if token == '+':
                    value = 'Suma'
                if token == '‐':
                    value = 'Resta'
                if token == '*':
                    value = 'Multiplicación'
                if token == '/':
                    value = 'División'
                if token == '^':
                    value = 'Potencia'
                if token == '(':
                    value = 'Paréntesis que abre'
                if token == ')':
                    value = 'Paréntesis que cerra'
            if (state == 'g'):
                value = "Variable"
            if state == 'h':
                value = 'Resta'
            if state == 'i':
                value = 'Division'
            if (state == 'j'):
                value = "Comentario"

            # adding 40 spaces for better writing
            for x in range(len(token), 40):
                token += " "
            #printing in console
            print("%s %s" % (token, value))

#Function to get arguments from user, set defaults and display help
def parse_args():
    parser = argparse.ArgumentParser(description='Train CNN base networks')
    parser.add_argument('--transitions', dest='transitions',
                        help='Text file with the transitions, check documentation for more details',
                        default='AFD.txt', type=str)
    parser.add_argument('--expresions', dest='expresions',
                        help='Text file with the expresions to evaluate',
                        default='expresions.txt', type=str)
    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()
    afd = AFD(args.transitions)
    afd.readFile(args.expresions)
    afd.chechTokens()
