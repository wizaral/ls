CC = clang
NAME = libmx

.DEFAULT_GOAL = all

MKDIR = mkdir -p
PRINT = printf
AR = ar rcs
RM = rm -rf

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

WFLAGS = -Wall -Wextra -Werror -Wpedantic
DFLAGS = -O0 -g3 -ftrapv -fstandalone-debug
IFLAGS = -I$(INC_DIR)

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(IFLAGS)

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

HDR = $(wildcard $(INC_DIR)*.h)
SRC = $(wildcard $(SRC_DIR)**/*.c)
DIRS = $(wildcard $(SRC_DIR)**)

define BUILD_template # 1 - target | 2 - flags

ifeq ($1,default)
NAME_$1 = $(NAME).a
else
NAME_$1 = $(NAME)_$1.a
endif

BUILD_NAMES += $$(NAME_$1)

OBJ_DIR_$1 = $(OBJ_DIR)$1/
OBJ_DIRS_$1 = $$(DIRS:$(SRC_DIR)%=$$(OBJ_DIR_$1)%)
OBJ_$1 = $(SRC:$(SRC_DIR)%.c=$$(OBJ_DIR_$1)%.o)

$$(OBJ_DIR_$1):
	@$(MKDIR) $$(OBJ_DIR) $$@ $$(OBJ_DIRS_$1)

$$(OBJ_DIR_$1)%.o: $$(SRC_DIR)%.c $$(HDR)
	@$(PRINT) "$K$G COMPILING $Y[$M$1$Y] $B$$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $2 -o $$@ -c $$<

$$(NAME_$1): $$(OBJ_DIR_$1) $$(OBJ_$1) $$(HDR)
	@$(PRINT) "$K$G ARCHIVING $Y[$M$1$Y] $R$$@$D\r"
	@$(AR) $$@ $$(OBJ_$1)
endef

$(eval $(call BUILD_template,default,))
$(eval $(call BUILD_template,release,-Ofast -march=native -flto))
$(eval $(call BUILD_template,debug,$(DFLAGS)))
$(eval $(call BUILD_template,debug_address,$(DFLAGS) -fsanitize=address -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_undefined,$(DFLAGS) -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow))
$(eval $(call BUILD_template,debug_address_undefined,$(DFLAGS) -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_leak,$(DFLAGS) -fsanitize=address))
$(eval $(call BUILD_template,debug_memory,$(DFLAGS) -fsanitize=memory))
$(eval $(call BUILD_template,debug_thread,$(DFLAGS) -fsanitize=thread))

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

clean:
	@$(RM) $(OBJ_DIR)

uninstall:
	@$(RM) $(OBJ_DIR) $(BUILD_NAMES)

reinstall: uninstall all

.PHONY: all clean uninstall reinstall
