echo "Enter two numbers: "
read a
read b

echo "Select operation:
1. Addition
2. Subtraction
3. Multiplication
4. Division"

read choice

case $choice in
    1)
        result=$(($a + $b))
        echo "Addition of two entered numbers is $result"
        ;;
    2)
        result=$(($a - $b))
        echo "Subtraction of two entered numbers is $result"
        ;;
    3)
        result=$(($a * $b))
        echo "Multiplication of two entered numbers is $result"
        ;;
    4)
        if [ $b -ne 0 ]; then
            result=$(($a / $b))
            echo "Division of two entered numbers is $result"
        else
            echo "Cannot divide by zero"
        fi
        ;;
    *)
        echo "Invalid choice"
        ;;
esac


#2. Area and perimeter of a circle
echo "Enter the radius of the circle"
read r
echo "Area of the circle is $(echo 3.14*$r*$r |bc) sq units"
echo "Perimeter of the circle is $(echo 3.14*2*$r |bc) units"
echo ""

#3. Gross salary
#DA 1.65%, HRA 0.30% of basic salary
echo "Enter basic salary"
read sal
echo "Gross salary is Rs $(echo 0.0165*$sal + 0.003*$sal + $sal |bc)"
echo ""

#4. Calculate mean salary if basic salaries are 1200, 1400, 1350, 1800
val=$(echo 1200+1400+1350+1800 |bc)
val=$(echo $val/4 |bc)
echo "Mean basic salary is $val"
echo ""

