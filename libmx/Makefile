CC = clang
NAME = libmx

# set default rule
.DEFAULT_GOAL = all

MKDIR = mkdir -p
PRINT = printf
AR = ar rcs
RM = rm -rf

# colors
R = \033[1;91m
G = \033[1;92m
Y = \033[1;93m
B = \033[1;94m
M = \033[1;95m
C = \033[1;96m
S = \033[38;5;45;1m
D = \033[0m
F = \033[5m
K = \033[K

# warning flags
WFLAGS = -Wall -Wextra -Werror -Wpedantic
# debug flags
DFLAGS = -O0 -g3 -ftrapv -fstandalone-debug
# include flags
IFLAGS = -I$(INC_DIR)

# compilation of translation unit
COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(IFLAGS)

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

# collect headers
HDR = $(wildcard $(INC_DIR)*.h)
# collect source files
SRC = $(wildcard $(SRC_DIR)**/*.c)
# collect subdirectories in source directory
DIRS = $(wildcard $(SRC_DIR)**)

# template for building version of target with different compilation flags
define BUILD_template # 1 - target | 2 - flags

# add build type in name if it isn't default build
ifeq ($1,default)
NAME_$1 = $(NAME).a
else
NAME_$1 = $(NAME)_$1.a
endif

# add name of target file to list of build targets
BUILD_NAMES += $$(NAME_$1)

# create name of subdirectory for subdirectories with object files
OBJ_DIR_$1 = $(OBJ_DIR)$1/
# create names of subdirectories with object files
OBJ_DIRS_$1 = $$(DIRS:$(SRC_DIR)%=$$(OBJ_DIR_$1)%)
# create names of object files
OBJ_$1 = $(SRC:$(SRC_DIR)%.c=$$(OBJ_DIR_$1)%.o)

# rule for creating subdirectories for object files
$$(OBJ_DIR_$1):
	@$(MKDIR) $$(OBJ_DIR) $$@ $$(OBJ_DIRS_$1)

# rules for compilation every object file that depend on source file and header files
$$(OBJ_DIR_$1)%.o: $$(SRC_DIR)%.c $$(HDR)
	@$(PRINT) "$K$G COMPILING $Y[$M$1$Y] $B$$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $2 -o $$@ -c $$<

# rule for creating static library from object files
$$(NAME_$1): $$(OBJ_DIR_$1) $$(OBJ_$1) $$(HDR)
	@$(PRINT) "$K$G ARCHIVING $Y[$M$1$Y] $R$$@$D\r"
	@$(AR) $$@ $$(OBJ_$1)
endef

# generates build targets from template
$(eval $(call BUILD_template,default,))
$(eval $(call BUILD_template,release,-Ofast -march=native -flto))
$(eval $(call BUILD_template,debug,$(DFLAGS)))
$(eval $(call BUILD_template,debug_address,$(DFLAGS) -fsanitize=address -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_undefined,$(DFLAGS) -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow))
$(eval $(call BUILD_template,debug_address_undefined,$(DFLAGS) -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_leak,$(DFLAGS) -fsanitize=address))
$(eval $(call BUILD_template,debug_memory,$(DFLAGS) -fsanitize=memory))
$(eval $(call BUILD_template,debug_thread,$(DFLAGS) -fsanitize=thread))

# default rule
all: $(BUILD_NAMES)
	@$(PRINT) "$K$S╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗\n\
	║                                                                                                   ║\n\
	║       $C██$M╗     $C██$M╗$C██████$M╗           $C██$M╗$C███████$M╗    $C██████$M╗ $C███████$M╗ $C█████$M╗ $C██████$M╗ $C██$M╗   $C██$M╗       $S║\n\
	║       $C██$M║     $C██$M║$C██$M╔══$C██$M╗$F$Y▄ ██$G╗$Y▄$D    $C██$M║$C██$M╔════╝    $C██$M╔══$C██$M╗$C██$M╔════╝$C██$M╔══$C██$M╗$C██$M╔══$C██$M╗╚$C██$M╗ $C██$M╔╝       $S║\n\
	║       $C██$M║     $C██$M║$C██████$M╔╝ $F$Y████$G╗$D    $C██$M║$C███████$M╗    $C██████$M╔╝$C█████$M╗  $C███████$M║$C██$M║  $C██$M║ ╚$C████$M╔╝        $S║\n\
	║       $C██$M║     $C██$M║$C██$M╔══$C██$M╗$F$Y▀$G╚$Y██$G╔$Y▀$D    $C██$M║╚════$C██$M║    $C██$M╔══$C██$M╗$C██$M╔══╝  $C██$M╔══$C██$M║$C██$M║  $C██$M║  ╚$C██$M╔╝         $S║\n\
	║       $C███████$M╗$C██$M║$C██████$M╔╝  $F$G╚═╝$D     $C██$M║$C███████$M║    $C██$M║  $C██$M║$C███████$M╗$C██$M║  $C██$M║$C██████$M╔╝   $C██$M║          $S║\n\
	║       $M╚══════╝╚═╝╚═════╝           ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝          $S║\n\
	║                                                                                                   ║\n\
	╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝\n$D"

# deletes directory with object files
clean:
	@$(RM) $(OBJ_DIR)

# deletes directory with object files and libraries
uninstall:
	@$(RM) $(OBJ_DIR) $(BUILD_NAMES)

reinstall: uninstall all

# prevents errors if some item in current directory named same as one of this targets
.PHONY: all clean uninstall reinstall
