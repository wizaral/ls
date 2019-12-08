NAME = libmx.a
CC = clang

# я сюда ещё не добавил все src файлы библиотеки
# если сильно приспичит что-то скомпилить, то вставляй свою либу
# желательно не трогая этот проект

algorithm = binary_search bubblesort quicksort

file = get_file_length file_to_str read_line

list = clear_list create_node foreach_list list_size pop_back pop_front \
	pop_index push_back push_front push_index sort_list

memory = memccpy memchr memcmp memcpy memmem memmove memrchr memset realloc

print = print_strarr print_unicode printchar printerr printint printstr

string = atoi count_substr count_words del_extra_spaces del_strarr \
	get_char_index get_num_length get_substr_index hex_to_nbr itoa nbr_to_hex \
	replace_substr str_reverse strcat strchr strcmp strcpy strdel strdup \
	strjoin strlen strncmp strncpy strndup strnew strsplit strstr strtrim \
	tolower toupper

type = isalpha isdigit ishex islower isspace isupper

utils = factorial foreach isodd isprime sum_digits max_ll min_ll max_ull
	min_ull pow sqrt swap_char swap_int swap_str swap_void

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(addprefix mx_, $(addsuffix .c, $(RAW))))
OBJ = $(addprefix $(OBJ_DIR), $(addprefix mx_, $(addsuffix .o, $(RAW))))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Weverything
LFLAGS = -Iinc
OFLAGS = -Ofast -march=native
DFLAGS = -g -fsanitize=address

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# install
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(OFLAGS) -o $@ -c $<

# debug
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

install: $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

uninstall:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all