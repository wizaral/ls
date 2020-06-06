CC = clang
LIB = libmx.a
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
LIB_DIR = libmx/

SRC = $(FILES:%=$(SRC_DIR)%.c)
OBJ = $(FILES:%=$(OBJ_DIR)%.o)
LIB_PATH = $(LIB_DIR)$(LIB)

WFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(LFLAGS)
EXEC_IT = make -sf Makefile
EXEC_LD = $(EXEC_IT) -C $(LIB_DIR)
PRINT = printf
MKDIR = mkdir -p
RM = /bin/rm -rf
TARGET = build

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

build: $(LIB) $(NAME)
	@$(PRINT) "$S╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗\n\
	║                                                                                                   ║\n\
	║       $C██$M╗   $C██$M╗$C██$M╗     $C███████$M╗    $C██$M╗$C███████$M╗    $C██████$M╗ $C███████$M╗ $C█████$M╗ $C██████$M╗ $C██$M╗   $C██$M╗       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C██$M╔════╝    $C██$M║$C██$M╔════╝    $C██$M╔══$C██$M╗$C██$M╔════╝$C██$M╔══$C██$M╗$C██$M╔══$C██$M╗╚$C██$M╗ $C██$M╔╝       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C███████$M╗    $C██$M║$C███████$M╗    $C██████$M╔╝$C█████$M╗  $C███████$M║$C██$M║  $C██$M║ ╚$C████$M╔╝        $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     ╚════$C██$M║    $C██$M║╚════$C██$M║    $C██$M╔══$C██$M╗$C██$M╔══╝  $C██$M╔══$C██$M║$C██$M║  $C██$M║  ╚$C██$M╔╝         $S║\n\
	║       $M╚$C██████$M╔╝$C███████$M╗$C███████$M║    $C██$M║$C███████$M║    $C██$M║  $C██$M║$C███████$M╗$C██$M║  $C██$M║$C██████$M╔╝   $C██$M║          $S║\n\
	║       $M ╚═════╝ ╚══════╝╚══════╝    ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝          $S║\n\
	║                                                                                                   ║\n\
	╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝\n$D"

$(OBJ_DIR):
	@$(MKDIR) $@ $(foreach dir, $(dirs), $@/$(dir))

$(LIB):
	@$(EXEC_LD) $(TARGET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(PRINT) "$K$G COMPILING $Y[$M$(TARGET)$Y] $B$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(PRINT) "$K$G COMPILING $Y[$M$(TARGET)$Y] $R$(NAME)$D\r"
	@$(COMPILE) $(CFLAGS) $(LIB_PATH) $(OBJ) -o $(NAME)
	@$(PRINT) "$K"

# silent mode without printing LOGO
install:
	@$(EXEC_LD) $@
	@$(EXEC_IT) $(NAME)

clean:
	@$(EXEC_LD) $@
	@$(RM) $(OBJ_DIR)

uninstall:
	@$(EXEC_LD) $@
	@$(RM) $(OBJ_DIR) $(NAME)

# silent rebuild project
reinstall: uninstall install

.PHONY: all build clean install uninstall reinstall
