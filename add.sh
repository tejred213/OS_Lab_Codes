read a; read b
c=`expr $a + $b | bc`
echo $c
