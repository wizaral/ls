cp ../LS/uls .

zsh compare.sh <(ls -l) <(ls -l) <(echo 'ls -l')
# zsh compare.sh <(ls --l) <(./uls --l) <(echo './uls --l')
# zsh compare.sh <(ls --l 2>&1) <(./uls --l 2>&1) <(echo './uls --l')

# sh compare.sh 'ls " -l"' './uls " -l"'
# sh compare.sh 'ls -- " ."' './uls -- " ."'

# sh compare.sh 'ls privet' './uls privet'
# sh compare.sh 'ls --privet' './uls --privet'
# sh compare.sh 'ls -- privet' './uls -- privet'
# sh compare.sh 'ls -- -privet' './uls -- -privet'

# sh compare.sh 'ls ~/Desktop/privet' './uls ~/Desktop/privet'
# sh compare.sh 'ls /Users/osoviak-kr' './uls /Users/osoviak-kr'
