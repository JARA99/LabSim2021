reset
set terminal pdfcairo
set output "output.pdf"

set title "Problema 2"
set key opaque

f(x) = exp(-(x**2)/2)-0.5
g(x) = 0

plot f(x) t "f(x)", g(x) t "Eje x"

set terminal qt