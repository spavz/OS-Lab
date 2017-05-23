read -p "Enter a string " s

len=${#s}
for (( i = len - 1 ; i >=0; i-- )); do
	a="$a${s:$i:1}"
done

echo "$a"

echo "$s" | rev
