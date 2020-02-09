diff $1 $2 &> /dev/null

if [[ $? == 1 ]] then
    echo -e "\[\033[1;31m\]error\[\033[0m\]"
else
    echo -e "\[\033[1;32m\]same\[\033[0m\]"
fi
