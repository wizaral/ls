lls: ls
all: install

install:
	@make -sC LS -f Makefile all

uninstall:
	@make -sC LS -f Makefile uninstall

reinstall:
	@make -sC LS -f Makefile reinstall

ls:
	@make -sC LS -f Makefile uls
