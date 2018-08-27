#!/bin/bash
#Daniel Charua A01017419

if [ $# -eq 0 ]
then
  echo "$0 : You must give/supply one integers"
  exit 1
fi

#cambia todos los numeros por nada, si el input no esta vacio hay letras o signos
if [[ -n ${1//[0-9]/} ]]; then
    echo "Error de input is not a integer number!"
    exit 1
fi

op=1
number=$1
for (( i = 0; i < ${#1}-1; ++i )); do
    op=`expr $op \* ${1:$i:1}`
done
echo "the multiplication of the digits of $1 is $op"
