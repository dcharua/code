#!/bin/bash
#Daniel Charua A01017419
 echo Familia WK_IT WK_MK | xargs -n 1 groupadd
 useradd -g  Familia -d /home/familia Emilio
 useradd -g Familia -d /home/familia Marcela
 useradd -g Familia -d /home/familia Bruno
 useradd -M -g WK_IT  -s /bin/bash Delgadillo
 useradd -M -g WK_MK -s /bin/bash Castaneda -e 2017-12-31
 # echo getent group WK_IT | xargs -n 1 passwd -x 60
 passwd -x 46 Delgadillo

 #echo Emilio Marcela Bruno Delgadillo Cataneda | xargs -n 1 userdel -r
 #echo Familia WK_IT WK_MK | xargs -n 1 groupdel
