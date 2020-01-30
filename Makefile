all: install go
lls: ls go

install:
	@make -sC LS -f Makefile all

uninstall:
	@make -sC LS -f Makefile uninstall

reinstall:
	@make -sC LS -f Makefile reinstall

ls:
	@make -sC LS -f Makefile uls

go:
	@./LS/uls
