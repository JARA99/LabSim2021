reset
set terminal pdfcairo
set output "output.pdf"
set title "Velocidad - Tiempo"
set xrange [0:12]
set yrange [-5:25]
set key opaque

f(x) = m*x+b
fit f(x) "v-t.dat" via m,b

#FLAG

#plot "v-t.dat" w xerrorbars t "Datos",  g(x) t "C aproximation" ls 4, f(x) t "Gnuplot aproximation" dt 3
#set terminal qt
