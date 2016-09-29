reset                                                                                                   
set title 'Raytracing Performance'
set ylabel 'time(sec)'
set style fill solid 1.0 border -1
set term png enhanced font 'Verdana,10'
set boxwidth 0.7
set grid
set output "plot.png"

plot "output.txt" using ($0):2:($0):xtic(1) w boxes lc variable notitle
