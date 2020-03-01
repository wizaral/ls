CC = clang
LIB = libmx.a
NAME = uls

base = errors main parse

get = access acl arrow attr bsize flags grp inode links name size suffix time \
	user

read = full hidden standart

sort = $(addprefix compare_, ascii time size)

write = $(addprefix write_, 1 C l m x)

RAW = $(addprefix base/, $(base)) $(addprefix get/, $(get)) \
	$(addprefix print/, $(print)) $(addprefix read/, $(read)) \
	$(addprefix sort/, $(sort)) $(addprefix write/, $(write))


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
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/base $(OBJ_DIR)/get $(OBJ_DIR)/print      \
	$(OBJ_DIR)/read $(OBJ_DIR)/sort $(OBJ_DIR)/write

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# install
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) -pipe $(WFLAGS) $(LFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) -pipe $(WFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# optimize
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