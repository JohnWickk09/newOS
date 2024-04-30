#1. even odd
echo "Checking even or odd" 

echo "Enter a number: "
read num

if [ $((num % 2)) -eq 0 ]
 then
    echo "Number is even"
else 
    echo "Number is odd"
fi

echo ""


#2. greatest number
echo "greatest number"
echo "enter number 1"
read num1
echo "enter number 2"
read num2
echo "enter number 3"
read num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
	echo "1st number is the greatest"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
	echo "2nd number is the greatest"
else
	echo "3rd number is the greatest"
fi
echo ""

#3. leap year
echo "checking leap year"
echo "enter the year"
read year
if [ `expr $year % 400` -eq 0 ]
then
	echo "leap year"
elif [ `expr $year % 4` -eq 0 ] && [ `expr $year % 100` -ne 0 ]
then
	echo "leap year"
else
	echo "not a leap year"
fi
echo "" 

#4. tax
echo "enter account balance"
read bal
echo "enter withdrawal ammount"
read amt
if [ $amt -gt $bal ]
then
	echo "insufficient balance"
	exit
fi

if [ $amt -lt 1500 ]
then
	tax=`expr "scale=2; "$amt"*0.03" |bc`
	echo "tax = $tax rs"
elif [ $amt -ge 1500 ] && [ $amt -lt 3000 ]
then
	tax=`expr "scale=2; "$amt"*0.04" |bc`
	echo "tax = $tax rs"
else 
	tax=`expr "scale=2; "$amt"*0.05" |bc`
	echo "tax = $tax rs"
fi
echo "Total amount withdrawn after deducting tax = $(echo "$amt-$tax" |bc)"


