cp ../LS/uls .

err=('-l' '-privet' '-l --' '-al --' '-la --' '-Al --' '-Aa --' '-aA --'
	'-f --' '-fA -- ' '-AkF@eGisTOnh Makefile ../Makefile / /dev /dev/fd /tmp/')

for i in "${err[@]}"; do
	zsh compare.sh <(ls $i 2>&1) <(./uls $i 2>&1) $i
	zsh compare.sh <(ls $i . 2>&1) <(./uls $i . 2>&1) "$i ."
	zsh compare.sh <(ls $i .. 2>&1) <(./uls $i .. 2>&1) "$i .."
done
