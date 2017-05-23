if (($# == 0)); then
	echo " no login names enterened "
	exit
fi

echo "Entered $1"
set -- `grep $1 /etc/passwd | cut -d':' -f 6`

echo "$1" 


