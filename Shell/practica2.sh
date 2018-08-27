#!/bin/bash
#Daniel Charua A01017419
 echo Parents Children Soho | xargs -n 1 groupadd
 echo Parents Children Soho | xargs -n 1 getent group
 echo Paul Jane | xargs -n 1 useradd -m -g Parents
 echo Derek Alice | xargs -n 1 useradd -m -g Children
 echo Accouts Sales | xargs -n 1 useradd -m -g Soho
 for user in Paul Jane Derek Alice Accouts Sales; do echo ${user}:generica | chpasswd ;done
 #echo Paul Jane Derek Alice Accouts Sales| xargs -n 1 userdel -r
 #echo Parents Children Soho | xargs -n 1 groupdel
