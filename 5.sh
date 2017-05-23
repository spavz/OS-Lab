stty -echo
read -p "Enter the password:" pass1
printf "\n"
read -p "Retype:" pass2


if [ $pass1 = $pass2 ]; then
	tput clear
	echo -e "The terminal is locked. Pass3:"
	read pass3
	while true; do
		if [ $pass1 = $pass3 ]; then
 			break
 		fi
 		read -p "Try again " pass3
	done
else
	printf "Mismatch\n"
fi
stty echo
