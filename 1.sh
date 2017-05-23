#!/bin/bash
x=$#
echo "Number: $x"
echo "Args: $*"

while (($x > 0)); do
	eval echo \$$x
	((x--))
done
