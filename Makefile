all:
	@make -sC LS -f Makefile all

clean:
	@make -sC LS -f Makefile clean

uninstall:
	@make -sC LS -f Makefile uninstall

reinstall:
	@make -sC LS -f Makefile reinstall
