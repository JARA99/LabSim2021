reset
set terminal pdfcairo
set output "Cohete1.pdf"

set autoscale

plot "../DAT/vh1-t.dat" using 1:2 t "Velocidad del objeto 1"

set terminal qt