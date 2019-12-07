CC = clang
LIB = libmx.a
NAME = uls

# тут перечень файлов в src без расширения, но с префиксом mx_ !
RAW = mx_main

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Weverything
LFLAGS = -Iinc -Ilibmx/inc
OFLAGS = -Ofast -march=native
DFLAGS = -g -fsanitize=address

# по дефолту вызывает компиляцию с флагами оптимизации
opt: optimize clean
all: install clean
dbg: debug clean
fff: full clean

# в задаче с дебагом нет клина папки *.dSYM, т.к. она нужна для дебага (неждан)
# но у нас этого флага не будет при пуше
# сама папка в игноре, так шо не бзди))

optimize: olib oname
install: ilib iname
debug: dlib dname
full: flib fname

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

ilib:
	@make -sC $(LIB_DIR) -f Makefile install

iname: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

dlib:
	@make -sC $(LIB_DIR) -f Makefile debug

dname: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

olib:
	@make -sC $(LIB_DIR) -f Makefile optimize

oname: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

flib:
	@make -sC $(LIB_DIR) -f Makefile full

fname: $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all