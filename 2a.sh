a=$1
b=$2
set -- `ls -l $a`
x=$1
set -- `ls -l $b`
y=$1

echo $x
echo $y


if [ $x == $y ] ; then
	echo "equal"
	echo $x
else
	echo "not equal"
	echo "$a $x"
	echo "$b $y"
fi
