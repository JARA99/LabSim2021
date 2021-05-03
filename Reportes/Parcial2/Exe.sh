# !/bin/bash

# Author: Jorge Alejandro Rodriguez Aldana
# Type: Bash Script
# Exe: ./Exe.sh
# Resume: Automatize all

gcc Aceleration.c  -o  Aceleration
gcc Grafica.c -o Grafica

line=$(./Grafica)

rm output.gp
cp v-t.gp output.gp

echo $line >> output.gp
echo 'plot "v-t.dat" w xerrorbars t "Datos",  g(x) t "Aproximación de C", f(x) t "Aproximación de Gnuplot" ls 4  dt 3 lw 2' >> output.gp
echo 'set terminal qt' >> output.gp

gnuplot 'output.gp'
evince output.pdf