CC = clang
NAME = uls

# set default rule
.DEFAULT_GOAL = all

MKDIR = mkdir -p
PRINT = printf
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
# link directory flags
LFLAGS = # -L...
# link library flags
lFLAGS = # -l...

# compilation of translation unit
COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(IFLAGS)
# compilation of target
BUILD = $(COMPILE) $(LFLAGS) $(lFLAGS)

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

# collect headers
HDR = $(wildcard $(INC_DIR)*.h)
# collect source files
SRC = $(wildcard $(SRC_DIR)**/*.c)
# collect subdirectories in source directory
DIRS = $(wildcard $(SRC_DIR)**)

# template for using libraries of depend makefiles
define DEPENDENCY_template # 1 - include path | 2 - link path | 3 - link name

# sets -I flag before every include path ($1 could be list of directories)
DEP_IFLAGS += $$(foreach f, $1, $$(f:%=-I%))
# sets -L flag before link directory
DEP_LFLAGS += -L$2
# sets -l flag before link library
DEP_lFLAGS += -l$3
endef

# template for calling all depend makefiles
define DEPENDENT_MAKE_template # 1 - name | 2 - directory

# prevents errors if $1 target named same as one of items in current directory
.PHONY: $1 clean_$1 uninstall_$1

# add target for calling depend makefiles
MAKE_TARGETS += $1
# add current target in main target list of dependencies for building
BUILD_TARGETS += $2/$1
# add current target in main target list of dependencies for cleaning
CLEAN_TARGETS += clean_$1
# add current target in main target list of dependencies for uninstalling
UNINSTALL_TARGETS += uninstall_$1

# build target for dependency
$1:
	@$(MAKE) -sf Makefile -C $2

# clean target for dependency
clean_$1:
	@$(MAKE) -sf Makefile -C $2 clean

# uninstall target for dependency
uninstall_$1:
	@$(MAKE) -sf Makefile -C $2 uninstall
endef

# template for building version of target with different compilation flags
define BUILD_template # 1 - target | 2 - flags

# add build type in name if it isn't default build
ifeq ($1,default)
NAME_$1 = $(NAME)
else
NAME_$1 = $(NAME)_$1
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
	@$(COMPILE) $2 $$(DEP_IFLAGS) -o $$@ -c $$<

# rule for creating executable from object files
$$(NAME_$1): $$(OBJ_DIR_$1) $$(OBJ_$1) $$(HDR) $$(BUILD_TARGETS)
	@$(PRINT) "$K$G COMPILING $Y[$M$1$Y] $R$$@$D\r"
ifeq ($1,default)
	@$(BUILD) $2 $$(DEP_IFLAGS) $$(DEP_LFLAGS) $$(DEP_lFLAGS) $$(OBJ_$1) -o $$@
else
# if not default build, then should use libs with same build type
	@$(BUILD) $2 $$(DEP_IFLAGS) $$(DEP_LFLAGS) $$(foreach f, $$(DEP_lFLAGS), $$(f:%=%_$1)) $$(OBJ_$1) -o $$@
endif
endef

# generates linking to depend makefiles libraries
$(eval $(call DEPENDENCY_template,libmx/inc,libmx,mx))

# generates calling rules of depend makefiles
$(eval $(call DEPENDENT_MAKE_template,libmx.a,libmx))

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
all: $(MAKE_TARGETS) $(BUILD_NAMES)
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

# deletes directory with object files
clean: $(CLEAN_TARGETS)
	@$(RM) $(OBJ_DIR)

# deletes directory with object files and libraries
uninstall: $(UNINSTALL_TARGETS)
	@$(RM) $(OBJ_DIR) $(BUILD_NAMES)

reinstall: uninstall all

# prevents errors if some item in current directory named same as one of this targets
.PHONY: all clean uninstall reinstall
