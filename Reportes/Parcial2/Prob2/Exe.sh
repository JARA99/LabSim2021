# !/bin/bash

# Author: Jorge Alejandro Rodriguez Aldana
# Type: Bash Script
# Exe: ./Exe.sh
# Resume: Automatize all

gnuplot 'Graph.gp'

echo ''
gcc Root.c -lm -o  Root
./Root
echo ''

evince output.pdf