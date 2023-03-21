set title "fibonacci time"
set xlabel "nth fibonacci"
set ylabel "ns"
set terminal png font " Times_New_Roman,12 "
set output "time_fd_l.png"

plot \
"time_fd_l.txt" using 1:2 with linespoints linewidth 2 title "fast doubling", \
"time_fd_l.txt" using 1:3 with linespoints linewidth 2 title "fast doubling without clz" , \
"time_fd_l.txt" using 1:4 with linespoints linewidth 2 title "original" 
