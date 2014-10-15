#!/bin/bash
echo
a=`cat *.c* | wc -l`
b=`cat *.py | wc -l`
c=`expr " $a + $b" | bc -l`
d=`ls *.c* | wc -l`
e=`ls *.py | wc -l`
f=`expr " $d + $e" | bc -l`
g=`expr " $c / $f " | bc -l`
echo "Total Lines of Code: $c"
echo "C and CPP programs: $d"
echo "Python programs: $e"
echo "Total Number of programs: $f"
echo -n 'Lines of Code per program: '
printf "%.2f" $g
echo 
echo
exit 0
