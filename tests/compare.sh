diff $1 $2 &> /dev/null

if [[ $? == 2 ]]; then
	echo "\033[1;31merror: $3\033[0m"
elif [[ $? == 1]]; then
	echo "\033[1;31mnot same: $3\033[0m"
else
	echo "\033[1;32msame: $3\033[0m"
fi
