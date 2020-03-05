diff $1 $2 &> /dev/null
var=$?

if [[ $var == 0 ]]; then
	echo "\033[1;32mSame: $3\033[0m"
elif [[ $var == 1 ]]; then
	echo "\033[1;31mFailed: $3\033[0m"
	# diff -y <(ls $3 2>&1) <(./uls $3 2>&1)
else
	echo "\033[1;5;31mError: $3\033[0m"
fi
