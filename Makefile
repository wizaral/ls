CC = clang
LIB = libmx.a
NAME = uls

RAW = mx_main mx_num_of_cols mx_print mx_uls mx_lflag mx_lflag_linksnum \
	mx_l_flag_spaces mx_printlflag 

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -pipe -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -fsanitize=address

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# install
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# debug
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(WFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(WFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall install