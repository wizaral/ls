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

all: install clean

# в задаче с дебагом нет клина папки *.dSYM, т.к. она нужна для дебага (неждан)
# но у нас этого флага не будет при пуше
# сама папка в игноре, так шо не бзди))

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# чтобы нормально переключаться между типами компиляции нужно коментить одно
# и раскоментить другое. другого варианта как это красиво сделать я не придумал
# всё равно приходится копировать команды. те же действия в либе сделай!
# советую пока что работать на install сборке, потом будет оптимизации трогать

# install
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# debug
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all