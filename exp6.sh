#printing star patterns
echo "Enter number of stars: "
read num
echo "Half Diamond Pattern"
echo
for((i=0;i<num;i++))
do
	for((j=0;j<i+1;j++))
	do
		echo -n "*"
	done
	echo
	done
for((i=num-1;i>=0;i--))
do
	for((j=i;j>0;j--))
	do
		echo -n "*"
	done
	echo
	done
	
echo "Full Diamond Pattern"
echo

for ((i=0; i<num; i++))
do
    for ((j=num-i; j>1; j--))
    do
        echo -n " "
    done

    for ((j=0; j<i*2+1; j++))
    do
        echo -n "*"
    done

    echo
done

for ((i=num-2; i>=0; i--))
do
    for ((j=num-i; j>1; j--))
    do
        echo -n " "
    done

    for ((j=0; j<i*2+1; j++))
    do
        echo -n "*"
    done

    echo
done

echo "Triangle Pattern"
echo

for ((i=0; i<num; i++))
do
    for ((j=num-i; j>1; j--))
    do
        echo -n " "
    done

    for ((j=0; j<i*2+1; j++))
    do
        echo -n "*"
    done

    echo
done


echo "Hourglass Pattern"
echo

for ((i=num-2; i>=0; i--))
do
    for ((j=num-i; j>1; j--))
    do
        echo -n " "
    done

    for ((j=0; j<i*2+1; j++))
    do
        echo -n "*"
    done

    echo
done

echo

for ((i=0; i<num; i++))
do
    for ((j=num-i; j>1; j--))
    do
        echo -n " "
    done

    for ((j=0; j<i*2+1; j++))
    do
        echo -n "*"
    done

    echo
done


