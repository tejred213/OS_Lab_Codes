echo "Enter First Number1"
read Number1
echo "Enter Second Number2"
read Number2

echo "Enter Your choice"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

read var
case $var in
1) echo `expr $Number1 + $Number2 | bc`;;
2) echo `expr $Number1 - $Number2 | bc`;;
3) echo `expr $Number1 \* $Number2`;;
4) echo `expr $Number1 / $Number2`;;
*) echo Option Not available;;
esac

