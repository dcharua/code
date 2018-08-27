#!/bin/bash
cat Archivito.txt | xargs -n1 | sort | uniq -c 
