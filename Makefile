CC = clang
NAME = uls

.DEFAULT_GOAL = all

MKDIR = mkdir -p
PRINT = printf
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
LFLAGS = # -L...
lFLAGS = # -l...

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(IFLAGS)
BUILD = $(COMPILE) $(LFLAGS) $(lFLAGS)

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

SRC = $(wildcard $(SRC_DIR)**/*.c)
DIRS = $(wildcard $(SRC_DIR)**)

define DEPENDENCY_template # 1 - include path | 2 - link path | 3 - link name
DEP_IFLAGS += $$(foreach f, $1, $$(f:%=-I%))
DEP_LFLAGS += -L$2
DEP_lFLAGS += -l$3
endef

define DEPENDENT_MAKE_template # 1 - name | 2 - directory
.PHONY: $1

MAKE_LIBS += $1
BUILD_LIBS += $2/$1
CLEAN_LIBS += clean_$(notdir $(basename $1))
UNINSTALL_LIBS += uninstall_$(notdir $(basename $1))

$1:
	@$(MAKE) -sf Makefile -C $2

clean_$(notdir $(basename $1)):
	@$(MAKE) -sf Makefile -C $2 clean

uninstall_$(notdir $(basename $1)):
	@$(MAKE) -sf Makefile -C $2 uninstall
endef

define BUILD_template # 1 - target | 2 - flags
ifeq ($1,default)
NAME_$1 = $(NAME)
else
NAME_$1 = $(NAME)_$1
endif

BUILD_NAMES += $$(NAME_$1)
OBJ_DIR_$1 = $(OBJ_DIR)$1/
OBJ_DIRS_$1 = $$(DIRS:$(SRC_DIR)%=$$(OBJ_DIR_$1)%)
OBJ_$1 = $(SRC:$(SRC_DIR)%.c=$$(OBJ_DIR_$1)%.o)

$$(OBJ_DIR_$1):
	@$(MKDIR) $$(OBJ_DIR) $$@ $$(OBJ_DIRS_$1)

$$(OBJ_DIR_$1)%.o: $$(SRC_DIR)%.c
	@$(PRINT) "$K$G COMPILING $Y[$M$1$Y] $B$$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $2 $$(DEP_IFLAGS) -o $$@ -c $$<

$$(NAME_$1): $$(OBJ_DIR_$1) $$(OBJ_$1) $$(BUILD_LIBS)
	@$(PRINT) "$K$G COMPILING $Y[$M$1$Y] $R$$@$D\r"
ifeq ($1,default)
	@$(BUILD) $2 $$(DEP_IFLAGS) $$(DEP_LFLAGS) $$(DEP_lFLAGS) $$(OBJ_$1) -o $$@
else
	@$(BUILD) $2 $$(DEP_IFLAGS) $$(DEP_LFLAGS) $$(foreach f, $$(DEP_lFLAGS), $$(f:%=%_$1)) $$(OBJ_$1) -o $$@
endif
endef

$(eval $(call DEPENDENCY_template,libmx/inc,libmx,mx))

$(eval $(call DEPENDENT_MAKE_template,libmx.a,libmx))

$(eval $(call BUILD_template,default,))
$(eval $(call BUILD_template,release,-Ofast -march=native -flto))
$(eval $(call BUILD_template,debug,$(DFLAGS)))
$(eval $(call BUILD_template,debug_address,$(DFLAGS) -fsanitize=address -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_undefined,$(DFLAGS) -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow))
$(eval $(call BUILD_template,debug_address_undefined,$(DFLAGS) -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment))
$(eval $(call BUILD_template,debug_leak,$(DFLAGS) -fsanitize=address))
$(eval $(call BUILD_template,debug_memory,$(DFLAGS) -fsanitize=memory))
$(eval $(call BUILD_template,debug_thread,$(DFLAGS) -fsanitize=thread))

all: $(MAKE_LIBS) $(BUILD_NAMES)
	@$(PRINT) "$K$S╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗\n\
	║                                                                                                   ║\n\
	║       $C██$M╗   $C██$M╗$C██$M╗     $C███████$M╗    $C██$M╗$C███████$M╗    $C██████$M╗ $C███████$M╗ $C█████$M╗ $C██████$M╗ $C██$M╗   $C██$M╗       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C██$M╔════╝    $C██$M║$C██$M╔════╝    $C██$M╔══$C██$M╗$C██$M╔════╝$C██$M╔══$C██$M╗$C██$M╔══$C██$M╗╚$C██$M╗ $C██$M╔╝       $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     $C███████$M╗    $C██$M║$C███████$M╗    $C██████$M╔╝$C█████$M╗  $C███████$M║$C██$M║  $C██$M║ ╚$C████$M╔╝        $S║\n\
	║       $C██$M║   $C██$M║$C██$M║     ╚════$C██$M║    $C██$M║╚════$C██$M║    $C██$M╔══$C██$M╗$C██$M╔══╝  $C██$M╔══$C██$M║$C██$M║  $C██$M║  ╚$C██$M╔╝         $S║\n\
	║       $M╚$C██████$M╔╝$C███████$M╗$C███████$M║    $C██$M║$C███████$M║    $C██$M║  $C██$M║$C███████$M╗$C██$M║  $C██$M║$C██████$M╔╝   $C██$M║          $S║\n\
	║       $M ╚═════╝ ╚══════╝╚══════╝    ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝          $S║\n\
	║                                                                                                   ║\n\
	╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝\n$D"

clean: $(CLEAN_LIBS)
	@$(RM) $(OBJ_DIR)

uninstall: $(UNINSTALL_LIBS)
	@$(RM) $(OBJ_DIR) $(BUILD_NAMES)

reinstall: uninstall all

.PHONY: all clean uninstall reinstall
