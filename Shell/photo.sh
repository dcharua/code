#!/bin/bash
img_path=$0
nombre_liga='echo $img_path | tr '_' ' ' | awk '{print $3"_"$4}' | sed 's/e//' '
echo $nombre_liga
