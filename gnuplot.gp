set title "fibonacci time"
set xlabel "nth fibonacci"
set ylabel "ns"
set terminal png font " Times_New_Roman,12 "
set output "time.png"

plot "time.csv" using 1:2 with linespoints linewidth 2 title "fast doubling"
