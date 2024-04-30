while true;
do
clear
echo "Select an option: "
echo "1. Display current time in 24 hour format"
echo "2. Display current time in 12 hour format"
echo "3. Display today's date"
echo "4. Display today's date and time"
echo "5. Display time in GMT time zone"
echo "6. Exit"

read choice

case $choice in
1)
	echo "You selected option 1"
	echo "The current time is : $(date+"%H:%M:%S")"
	read -p "Press enter to contunue"
	;;
*)
	echo "a"
esac
done
