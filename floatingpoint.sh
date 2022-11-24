read a
1.1
read b
2.2
c=`echo $a + $b | bc`
echo $c

c= $(echo "scale=2; $a / $b" _|_ bc);;
