cp ../LS/uls .

sh compare.sh <ls --l <./uls --l
# sh compare.sh 'ls " -l"' './uls " -l"'
# sh compare.sh 'ls -- " ."' './uls -- " ."'

# sh compare.sh 'ls privet' './uls privet'
# sh compare.sh 'ls --privet' './uls --privet'
# sh compare.sh 'ls -- privet' './uls -- privet'
# sh compare.sh 'ls -- -privet' './uls -- -privet'

# sh compare.sh 'ls ~/Desktop/privet' './uls ~/Desktop/privet'
# sh compare.sh 'ls /Users/osoviak-kr' './uls /Users/osoviak-kr'