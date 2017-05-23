if (($# == 0)); then
	echo -e " No argument"
	exit
fi

if [ ! -d "$1" ]; then
	echo "the given directory does not exist "
	exit
fi

echo "Current dir: $1"
cd $1

set -- `ls -lR | grep -v "^d" | sort -nrk 5`
echo -e " The largest block is $5 and name: $9" 
