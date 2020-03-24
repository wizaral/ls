CC = clang
LIB = libmx
NAME = uls

base = check_flags compress_flags main parse proces_args uls

get = access arrow bsize dummy grp inode links name size suffix time user

read = full hidden standart

sort = argv ascii_reverse ascii time_reverse time size_reverse size

utils = errors free_dir get_data_len get_tabs inode_bsize path_name winsize

write = 1 C CG l m name total x xG

dirs = base get read sort utils write
FILES = $(foreach dir, $(dirs), $($(dir):%=$(dir)/%))

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(FILES:%=$(SRC_DIR)%.c)
OBJ = $(FILES:%=$(OBJ_DIR)%.o)
LIB_PATH = $(LIB:%=$(LIB)/%.a)

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -fsanitize=address -ftrapv

COMPILE = $(CC) -pipe $(WFLAGS) $(LFLAGS)
RM = /bin/rm -rf
TARGET = build

# checking about debugging in current project
DEBUG_OBJ = $(shell nm $(OBJ) 2> /dev/null | grep -m1 asan)
DEBUG_BIN = $(shell nm $(NAME) 2> /dev/null | grep -m1 asan)
DEBUG_LIB = $(shell nm $(LIB_PATH) 2> /dev/null | grep -m1 asan)

R = \033[1;91m
G = \033[1;92m
Y = \033[1;93m
B = \033[1;94m
M = \033[1;95m
C = \033[1;96m
S = \033[38;5;45;1m
D = \033[0m
F = \033[5m
A = \033[A
K = \033[K

all: build

# recursion call this make with initialized variables
debug:
	@make TARGET=debug CFLAGS='$(DFLAGS)' -s install

build: check $(LIB) $(NAME)
	@printf "$S╔═════════════════════════════════════════════\
	══════════════════════════════════════════════════════╗\n\
	║                                                       \
	                                            ║\n\
	║       $C██$M╗   $C██$M╗$C██$M╗     $C███████$M╗    \
	$C██$M╗$C███████$M╗    $C██████$M╗ $C███████$M╗ \
	$C█████$M╗ $C██████$M╗ $C██$M╗   $C██$M╗       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C██$M╔════╝    \
	$C██$M║$C██$M╔════╝    $C██$M╔══$C██$M╗$C██$M╔════╝$C██\
	$M╔══$C██$M╗$C██$M╔══$C██$M╗╚$C██$M╗ $C██$M╔╝       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C███████$M╗    \
	$C██$M║$C███████$M╗    $C██████$M╔╝$C█████$M╗  \
	$C███████$M║$C██$M║  $C██$M║ ╚$C████$M╔╝        $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     ╚════$C██$M║    \
	$C██$M║╚════$C██$M║    $C██$M╔══$C██$M╗$C██$M╔══╝  \
	$C██$M╔══$C██$M║$C██$M║  $C██$M║  ╚$C██$M╔╝         $S║\n\
	║       $M╚$C██████$M╔╝$C███████$M╗$C███████$M║    \
	$C██$M║$C███████$M║    $C██$M║  $C██$M║$C███████$M╗\
	$C██$M║  $C██$M║$C██████$M╔╝   $C██$M║          $S║\n\
	║       $M ╚═════╝ ╚══════╝╚══════╝    ╚═╝╚══════╝    \
	╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝          $S║\n\
	║                                                       \
	                                            ║\n\
	╚════════════════════════════════════════════════════\
	═══════════════════════════════════════════════╝\n$D"

# check debug level collision during this compilation
check:
ifeq ($(TARGET),build)
ifneq ($(findstring asan,$(DEBUG_LIB)),)
	@make -sC $(LIB) -f Makefile uninstall
	@$(RM) $(NAME)
endif
ifneq ($(or $(findstring asan,$(DEBUG_OBJ)), $(findstring asan,$(DEBUG_BIN))),)
	@$(RM) $(OBJ_DIR) $(NAME)
endif
else
ifeq ($(findstring asan,$(DEBUG_LIB)),)
	@make -sC $(LIB) -f Makefile uninstall
	@$(RM) $(NAME)
endif
ifeq ($(and $(findstring asan,$(DEBUG_OBJ)), $(findstring asan,$(DEBUG_BIN))),)
	@$(RM) $(OBJ_DIR) $(NAME)
endif
endif

$(OBJ_DIR):
	@mkdir -p $@ $(foreach dir, $(dirs), $@/$(dir))

$(LIB):
	@make -sC $(LIB) -f Makefile $(TARGET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $B$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)
	@printf "$K"

# silent mode without printing LOGO
install: check
	@make -sC $(LIB) -f Makefile install
	@make -s $(NAME)

clean:
	@make -sC $(LIB) -f Makefile clean
	@$(RM) $(OBJ_DIR)

uninstall:
	@make -sC $(LIB) -f Makefile uninstall
	@$(RM) $(OBJ_DIR) $(NAME)

# silent rebuild project
reinstall: uninstall
	@make -sC $(LIB) -f Makefile install
	@make -s $(NAME)

.PHONY: all build debug clean install uninstall reinstall $(LIB) $(NAME)
