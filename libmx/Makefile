CC = clang
NAME = libmx.a

algorithm = bsearch checksort lsearch quicksort sort

file = get_file_length file_to_str read_line

memory = memccpy memchr memcmp memcpy memdup memmem memmove memrchr memset    \
	realloc

print = print_strarr print_unicode printchar printnum printstr printstrlen    \
	printunum

string = atoll atoull count_substr count_words del_extra_spaces del_strarr    \
	get_char_index get_substr_index htoull lltoa_s lltoa replace_substr       \
	str_reverse strcat strchr strcmp strcpy strdel strdup strjoin strlen      \
	strncmp strncpy strndup strnew strsplit strstr strtrim tolower toupper    \
	ulltoa_s ulltoa ulltoh_s ulltoh

type = isalpha isdigit ishex islower isprint isspace isupper

utils = factorial foreach isprime numlen pow sigma sqrt_natural sqrt          \
	sum_digits swap unumlen

vector = assign_vector at clear_vector copy_vector create_vector              \
	delete_vector end erase foreach_vector foreach_vector_reverse get_back    \
	get_front insert pop_backward push_backward reverse_vector

dirs = algorithm file memory print string type utils vector
FILES = $(foreach dir, $(dirs), $($(dir):%=$(dir)/mx_%))

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(FILES:%=$(SRC_DIR)%.c)
OBJ = $(FILES:%=$(OBJ_DIR)%.o)

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc
CFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -glldb -fsanitize=address -ftrapv

COMPILE = $(CC) -pipe $(WFLAGS) $(LFLAGS)
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
K = \033[K

all: build

debug: CFLAGS = $(DFLAGS)
debug: TARGET = debug
debug: install

build: install
	@printf "$S╔═════════════════════════════════════════════\
	══════════════════════════════════════════════════════╗\n\
	║                                                       \
	                                            ║\n\
	║       $C██$M╗     $C██$M╗$C██████$M╗           \
	$C██$M╗$C███████$M╗    $C██████$M╗ $C███████$M╗ \
	$C█████$M╗ $C██████$M╗ $C██$M╗   $C██$M╗       $S║\n\
	║       $C██$M║     $C██$M║$C██$M╔══$C██$M╗$F$Y▄ ██$G╗$Y▄$D    \
	$C██$M║$C██$M╔════╝    $C██$M╔══$C██$M╗$C██$M╔════╝$C██\
	$M╔══$C██$M╗$C██$M╔══$C██$M╗╚$C██$M╗ $C██$M╔╝       $S║\n\
	║       $C██$M║     $C██$M║$C██████$M╔╝ $F$Y████$G╗$D    \
	$C██$M║$C███████$M╗    $C██████$M╔╝$C█████$M╗  \
	$C███████$M║$C██$M║  $C██$M║ ╚$C████$M╔╝        $S║\n\
	║       $C██$M║     $C██$M║$C██$M╔══$C██$M╗$F$Y▀$G╚$Y██$G╔$Y▀$D    \
	$C██$M║╚════$C██$M║    $C██$M╔══$C██$M╗$C██$M╔══╝  \
	$C██$M╔══$C██$M║$C██$M║  $C██$M║  ╚$C██$M╔╝         $S║\n\
	║       $C███████$M╗$C██$M║$C██████$M╔╝  $F$G╚═╝$D     \
	$C██$M║$C███████$M║    $C██$M║  $C██$M║$C███████$M╗$C██$M║  \
	$C██$M║$C██████$M╔╝   $C██$M║          $S║\n\
	║       $M╚══════╝╚═╝╚═════╝           ╚═╝╚══════╝    \
	╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝          $S║\n\
	║                                                       \
	                                            ║\n\
	╚════════════════════════════════════════════════════\
	═══════════════════════════════════════════════╝\n$D"

$(OBJ_DIR):
	@mkdir -p $@ $(foreach dir, $(dirs), $@/$(dir))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@printf "$K$G COMPILING $Y[$M$(TARGET)$Y] $B$(<:$(SRC_DIR)%=%)$D\r"
	@$(COMPILE) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@printf "$K$G ARCHIVING $Y[$M$(TARGET)$Y] $R$(NAME)$D\r"
	@ar rcs $(NAME) $(OBJ)
	@printf "$K"

install: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

uninstall:
	@$(RM) $(OBJ_DIR) $(NAME)

reinstall: uninstall install

.PHONY: all build debug clean install uninstall reinstall
