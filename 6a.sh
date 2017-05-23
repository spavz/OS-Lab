a=$1
b=$2
c=$3

if [ $a -gt $b ]; then
	temp=$a
else
	temp=$b
fi

if [ $temp -gt $c ]; then
	echo -e "Biggest is $temp"
else
	echo -e "Biggest is $c"
fi
