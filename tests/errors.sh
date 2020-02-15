cp ../LS/uls .

zsh compare.sh <(ls --l 2>&1) <(./uls --l 2>&1) 'ls --l'
zsh compare.sh <(ls --l . 2>&1) <(./uls --l . 2>&1) 'ls --l .'

zsh compare.sh <(ls privet 2>&1) <(./uls privet 2>&1) 'ls privet'
zsh compare.sh <(ls privet . 2>&1) <(./uls privet . 2>&1) 'ls privet .'

zsh compare.sh <(ls --privet 2>&1) <(./uls --privet 2>&1) 'ls --privet'
zsh compare.sh <(ls --privet . 2>&1) <(./uls --privet . 2>&1) 'ls --privet .'

zsh compare.sh <(ls -- privet 2>&1) <(./uls -- privet 2>&1) 'ls -- privet'
zsh compare.sh <(ls -- privet . 2>&1) <(./uls -- privet . 2>&1) 'ls -- privet .'
zsh compare.sh <(ls -- -privet 2>&1) <(./uls -- -privet 2>&1) 'ls -- -privet'
zsh compare.sh <(ls -- -privet . 2>&1) <(./uls -- -privet . 2>&1) 'ls -- -privet .'

zsh compare.sh <(ls ~/Desktop/privet 2>&1) <(./uls ~/Desktop/privet 2>&1) 'ls ~/Desktop/privet'
zsh compare.sh <(ls /Users/neo 2>&1) <(./uls /Users/neo 2>&1) '/Users/neo'
