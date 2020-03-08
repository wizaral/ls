CC = clang
LIB = libmx.a
NAME = uls

base = errors check_flags compress_flags main parse proces_args uls

get = access acl arrow attr bsize dummy flags grp inode links name size       \
	suffix time user

read = full hidden standart

sort = argv_reverse argv ascii_reverse ascii time_reverse time size_reverse   \
	size

utils = check_block_char get_data_len get_tabs inode_bsize octal path_name    \
	winsize

write = 1 C CG l m name total x xG

RAW = $(addprefix base/, $(base)) $(addprefix get/, $(get))                   \
	$(addprefix read/, $(read)) $(addprefix sort/, $(sort))                   \
	$(addprefix utils/, $(utils)) $(addprefix write/, $(write))

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -fsanitize=address

all: install

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/base $(OBJ_DIR)/get $(OBJ_DIR)/read       \
	$(OBJ_DIR)/sort $(OBJ_DIR)/utils $(OBJ_DIR)/write

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# install
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) -pipe $(WFLAGS) $(LFLAGS) $(CFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) -pipe $(WFLAGS) $(LFLAGS) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# debug
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -pipe $(WFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) -pipe $(WFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall install