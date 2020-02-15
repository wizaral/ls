cp ../LS/uls .

zsh compare.sh <(ls -l 2>&1) <(./uls -l 2>&1) 'ls -l'

zsh compare.sh <(ls -l -- 2>&1) <(./uls -l -- 2>&1) 'ls -l --'
zsh compare.sh <(ls -l -- . 2>&1) <(./uls -l -- . 2>&1) 'ls -l -- .'
zsh compare.sh <(ls -l -- .. 2>&1) <(./uls -l -- .. 2>&1) 'ls -l -- ..'

zsh compare.sh <(ls -al -- 2>&1) <(./uls -al -- 2>&1) 'ls -al --'
zsh compare.sh <(ls -la -- 2>&1) <(./uls -la -- 2>&1) 'ls -la --'
zsh compare.sh <(ls -al -- . 2>&1) <(./uls -al -- . 2>&1) 'ls -al -- .'
zsh compare.sh <(ls -la -- . 2>&1) <(./uls -la -- . 2>&1) 'ls -la -- .'
zsh compare.sh <(ls -al -- .. 2>&1) <(./uls -al -- .. 2>&1) 'ls -al -- ..'
zsh compare.sh <(ls -la -- .. 2>&1) <(./uls -la -- .. 2>&1) 'ls -la -- ..'

zsh compare.sh <(ls -Al -- 2>&1) <(./uls -Al -- 2>&1) 'ls -Al --'
zsh compare.sh <(ls -Al -- .. 2>&1) <(./uls -Al -- .. 2>&1) 'ls -Al -- ..'

zsh compare.sh <(ls -aA --  2>&1) <(./uls -aA --  2>&1) 'ls -aA -- '
zsh compare.sh <(ls -Aa --  2>&1) <(./uls -Aa --  2>&1) 'ls -Aa -- '

zsh compare.sh <(ls -f --  2>&1) <(./uls -f --  2>&1) 'ls -f -- '
zsh compare.sh <(ls -fA --  2>&1) <(./uls -fA --  2>&1) 'ls -fA -- '
