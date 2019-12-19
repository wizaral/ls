#ifndef LIBMX_H
#define LIBMX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

#include "types.h"
#include "structs.h"
#include "macroses.h"

/*
* algorithm
*/

/*
* bsearch and lsearch return 0 if have not found item, so you need to
* check first item in container
*/

t_ull mx_binary_search(t_cv *key, t_cvector *v, int (*cmp)(t_cv *, t_cv *));
t_ull mx_linear_search(t_cv *key, t_cvector *v, int (*cmp)(t_cv *, t_cv *));

/*
* sort needs comparator for two argumants
* quicksort needs weight func for one element
*/

void mx_sort(void *arr, size_t size, size_t bytes, int (*f)(t_cv *, t_cv *));
void mx_quicksort(void *arr, size_t size, size_t bytes, t_ull (*w)(t_cv *));

/*
* file
*/

char *mx_file_to_str(t_cc *file);
t_ll mx_get_file_length(t_cc *filename);
t_ll mx_read_line(char **lineptr, char delim, const int fd);

/*
* memory
*/

void *mx_memccpy(void *restrict dst, t_cv *restrict src, int c, size_t n);
void *mx_memchr(t_cv *s, int c, size_t n);
int mx_memcmp(t_cv *s1, t_cv *s2, size_t n);
void *mx_memcpy(void *restrict dst, t_cv *restrict src, size_t n);
void *mx_memdup(t_cv *src, size_t n);
void *mx_memmem(t_cv *big, size_t big_len, t_cv *little, size_t little_len);
void *mx_memmove(void *dst, t_cv *src, size_t len);
void *mx_memrchr(t_cv *s, int c, size_t n);
void *mx_memset(void *b, int c, size_t len);

void *mx_realloc(void *ptr, size_t size);

/*
* print
*/

void mx_print_strarr(t_cc **arr, t_cc *delim, const int fd);
void mx_print_unicode(wchar_t c, const int fd);

void mx_printchar(char c, const int fd);
void mx_printnum(t_ll n, const int fd);
void mx_printstr(t_cc *s, const int fd);
void mx_printunum(t_ull n, const int fd);

/*
* string
*/

t_ll mx_atoll(t_cc *str);
t_ull mx_atoull(t_cc *str);

int mx_count_substr(t_cc *str, t_cc *sub);
int mx_count_words(t_cc *str, char c);

char *mx_del_extra_spaces(t_cc *str);
void mx_del_strarr(char ***arr);

int mx_get_char_index(t_cc *str, char c);
int mx_get_substr_index(t_cc *str, t_cc *sub);

t_ull mx_hex_to_nbr(t_cc *hex);
char *mx_itoa(int number);
char *mx_nbr_to_hex(t_ull nbr);

char *mx_replace_substr(t_cc *str, t_cc *sub, t_cc *replace);
void mx_str_reverse(char *s);

char *mx_strcat(char *restrict s1, t_cc *restrict s2);
char *mx_strchr(t_cc *s, int c);

int mx_strcmp(t_cc *s1, t_cc *s2);
char *mx_strcpy(char *dst, t_cc *src);

void mx_strdel(char **str);
char *mx_strdup(t_cc *str);

char *mx_strjoin(t_cc *s1, t_cc *s2);
t_ull mx_strlen(t_cc *s);

int mx_strncmp(t_cc *s1, t_cc *s2, int n);
char *mx_strncpy(char *dst, t_cc *src, int len);
char *mx_strndup(t_cc *str, size_t n);

char *mx_strnew(const int size);
char **mx_strsplit(t_cc *s, char c);

char *mx_strstr(t_cc *haystack, t_cc *needle);
char *mx_strtrim(t_cc *str);

int mx_tolower(int c);
int mx_toupper(int c);

/*
* type
*/

bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_ishex(int c);

bool mx_islower(int c);
bool mx_isspace(int c);
bool mx_isupper(int c);

/*
* utils
*/

t_ull mx_factorial(t_ull n);
void mx_foreach(void *arr, t_ull size, size_t bytes, void(*f)(void *));

int mx_get_num_length(t_ll num, unsigned base);
bool mx_isprime(t_ull num);

double mx_pow(double n, unsigned pow);
t_ull mx_sigma(t_ull n);

t_ull mx_sqrt_natural(t_ull x);
double mx_sqrt(double x);
int mx_sum_digits(t_ull num);

void mx_swap(void *v1, void *v2, size_t size);

#endif
