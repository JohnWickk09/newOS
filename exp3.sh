# 1. checking if two strings are equal or not

echo "Enter the first word: "
read str1

echo "Enter the second word: "
read str2

if [ $str1 == $str2 ];
then
    echo "Strings are equal"
else
    echo "Strings are unequal"
fi
echo ""

# 2. concatenation

concat="$str1$str2"
echo "The concatenated string is $concat"
echo ""

# 3. finding the length of a string

length=$(expr length $concat)
echo "The length of the string is $length"
echo ""

# 4. Printing characters at odd positions

length2=$(expr length $str2)
for ((i = 0; i < length; i += 2)); do
    echo "${str1:i:1}"
done
echo ""

# 5. Checking palindrome

echo "Enter string: "
read str

reverse=""
length=$(expr length $str)

for ((i = length - 1; i >= 0; i--)); do
    reverse="$reverse${str:i:1}"
done

if [ $str == $reverse ]; then
    echo "It is a palindrome"
else
    echo "It is not a palindrome"
fi
echo ""

# 6. Reverse of string

echo "Reversed string is $reverse"
echo ""

# 7. Occurrence of a character in string

echo "enter a string: "
read st

echo "enter the character: "
read char

count=$(echo $st | grep -o $char | wc -l)
echo "the character $char appears $count times in the string $st"

