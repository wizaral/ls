all:
	@make -sC LS -f Makefile all

clean:
	@make -sC LS -f Makefile clean

uninstall:
	@make -sC LS -f Makefile uninstall

reinstall:
	@make -sC LS -f Makefile reinstall

debug:
	@clang -std=c11 -pipe \
	-I./LS/inc -I./LS/libmx/inc \
	-Wall -Wextra -Werror -Wpedantic \
	-O0 -g3 -glldb -fsanitize=address \
	./LS/src/*/*.c ./LS/libmx/src/*/*.c
