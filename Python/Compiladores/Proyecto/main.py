#dDaniel Charua - A01017419
import argparse

from globalTypes import *
from parser import *
from semantica import *
from cgen import *

#Function to get arguments from user, set defaults and display help
def parse_args():
    parser = argparse.ArgumentParser(description='Compiler C-')
    parser.add_argument('--input', dest='input',
                        help='Name of the file to read the c- code from. sample.c- by default',
                        default='sample.c-', type=str)
    parser.add_argument('--output', dest='output',
                        help='Name of the file to print the MIPS code. file.s by default',
                        default='file.s', type=str)
    parser.add_argument('--noPrint', dest='print',
                        help='Use flag to NOT print the AST and symbols', action='store_false')
    return parser.parse_args()

args = parse_args()
f = open(args.input, 'r')
programa = f.read()
progLong = len(programa)
programa = programa + '$'
posicion = 0

globales(programa, posicion, progLong)
AST = parser(args.print)
semantica(AST, args.print)
codeGen(AST, args.output)