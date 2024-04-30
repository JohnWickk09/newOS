list_processes() {

    echo "List all processes:"

    ps

}



process_info() {

    read -p "Enter the pid of the process: " pid

    echo "Information about process $pid:"

    ps -p $pid

}



global_priority() {

    read -p "Enter the pid of the process: " pid

    echo "Global priority of $pid:"

    ps -o pri,pid -p $pid

}



change_priority() {

    read -p "Enter the pid of the process: " pid

    read -p "Enter new priority (default: 10): " priority

    priority=${priority:-10}

    renice $priority $pid

    echo "Priority of process $pid changed to $priority"

}



while true; do

    echo "1) List processes"

    echo "2) Process info"

    echo "3) Global priority"

    echo "4) Change priority (default: 10)"

    echo "5) Exit"



    read -p "Choose option from 1 to 5: " choice

    case $choice in

        1) list_processes ;;

        2) process_info ;;

        3) global_priority ;;

        4) change_priority ;;

        5) echo "Exiting." ; exit ;;

        *) echo "Invalid option. Please choose again." ;;

    esac

done



chmod +x process_manager.sh

