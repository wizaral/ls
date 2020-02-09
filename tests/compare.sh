diff $1 $2 &> /dev/null

if [ $? != 0 ]; then
	echo "\033[1;31merror\033[0m"
else
	echo "\033[1;32msame\033[0m"
fi
