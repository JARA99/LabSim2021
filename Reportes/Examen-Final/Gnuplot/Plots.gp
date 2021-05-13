reset
set terminal jpeg

set output "Cohete1-v.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Velocidad del cohete"
plot "../DAT/vh1-t.dat" using 1:2 t "Velocidad del objeto 1" lc 1

set output "Cohete1-d.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Altura del cohete"
plot "../DAT/vh1-t.dat" using 1:3 t "Altura del objeto 1" lc 1

set output "Cohete1-vd.jpeg"
set xlabel "Velocidad del cohete"
set ylabel "Altura del cohete"
plot "../DAT/vh1-t.dat" using 2:3 t "Altura del objeto 1" lc 1

set output "Cohete2-v.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Velocidad del cohete"
plot "../DAT/vh2-t.dat" using 1:2 t "Velocidad del objeto 2" lc 2

set output "Cohete2-d.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Altura del cohete"
plot "../DAT/vh2-t.dat" using 1:3 t "Altura del objeto 2" lc 2

set output "Cohete2-vd.jpeg"
set xlabel "Velocidad del cohete"
set ylabel "Altura del cohete"
plot "../DAT/vh2-t.dat" using 2:3 t "Altura del objeto 2" lc 2

set output "Cohete3-v.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Velocidad del cohete"
plot "../DAT/vh3-t.dat" using 1:2 t "Velocidad del objeto 3" lc 3

set output "Cohete3-d.jpeg"
set xlabel "Tiempo transcurrido"
set ylabel "Altura del cohete"
plot "../DAT/vh3-t.dat" using 1:3 t "Altura del objeto 3" lc 3

set output "Cohete3-vd.jpeg"
set xlabel "Velocidad del cohete"
set ylabel "Altura del cohete"
plot "../DAT/vh3-t.dat" using 2:3 t "Altura del objeto 3" lc 3


set terminal qt