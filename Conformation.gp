#!bin/usr/gnuplot
set terminal pngcairo
set output "RDF.png"

set xrange[0:4.5]
set yrange[0:10]
set xlabel 'r' font "helvetica, 25" offset 0,0.5
set ylabel 'g(r)' font "helvetica, 25" offset 0,0
set border lw 2.0
set tics scale 1.5 
set key font "Arial,15"
set key top right box
set xtics font "Arial,15"
set ytics font "Arial,15"

plot "rdf.out" using 2:3 with lines lw 2 lt rgb "blue" ti "C-C"

unset xrange
unset yrange
unset label




