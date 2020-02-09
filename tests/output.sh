cp ../LS/uls .

sh compare.sh <ls -l $1 <./uls -l $1

# sh compare.sh 'ls -l --' './uls -l --'
# sh compare.sh 'ls -l -- .' './uls -l -- .'
# sh compare.sh 'ls -l -- ..' './uls -l -- ..'

# sh compare.sh 'ls -al --' './uls -al --'
# sh compare.sh 'ls -la --' './uls -la --'
# sh compare.sh 'ls -al -- .' './uls -al -- .'
# sh compare.sh 'ls -la -- .' './uls -la -- .'
# sh compare.sh 'ls -al -- ..' './uls -al -- ..'
# sh compare.sh 'ls -la -- ..' './uls -la -- ..'

# sh compare.sh 'ls -Al --' './uls -Al --'
# sh compare.sh 'ls -Al -- ..' './uls -Al -- ..'

# sh compare.sh 'ls -aA -- ' './uls -aA -- '
# sh compare.sh 'ls -Aa -- ' './uls -Aa -- '

# sh compare.sh 'ls -f -- ' './uls -f -- '
# sh compare.sh 'ls -fA -- ' './uls -fA -- '
