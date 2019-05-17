#dDaniel Charua - A01017419

def _globales(prog, pos, long, lexer):
  global programa
  global posicion
  global progLong
  global lines
  global char
  programa = prog
  posicion = pos
  progLong = long
  lines = programa.split('\n')
  char = list(map(lambda split: len(split) + 1, lines))
  lexer.input(programa)

def getPosicion(num):
  for i in range(len(char)):
    num -= char[i]
    if num < 0:
      num += char[i]
      break;
  return num