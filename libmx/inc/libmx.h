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

t_ll mx_linear_search(const void *key, const t_vector *v, int (*cmp)(const void *, const void *));
t_ll mx_binary_search(t_cv *key, t_vector *v, int (*cmp)(const void *, const void *));

void mx_bubblesort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));
void mx_quicksort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));
void mx_mergesort(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));

/*
* file
*/

char *mx_file_to_str(const char *file);
int mx_get_file_length(const char *filename);
int mx_read_line(char **lineptr, char delim, const int fd);

/*
* memory
*/

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memset(void *b, int c, size_t len);

void *mx_realloc(void *ptr, size_t size);

/*
* print
*/

void mx_print_strarr(const char **arr, const char *delim, const int fd);
void mx_print_unicode(wchar_t c, const int fd);

void mx_printchar(char c, const int fd);
void mx_printnum(t_ll n, const int fd);
void mx_printstr(const char *s, const int fd);
void mx_printunum(t_ull n, const int fd);

/*
* string
*/

int mx_atoi(const char *str);

int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);

char *mx_del_extra_spaces(const char *str);
void mx_del_strarr(char ***arr);

int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);

unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
char *mx_nbr_to_hex(unsigned long nbr);

char *mx_replace_substr(const char *str, const char *sub, const char *replace);
void mx_str_reverse(char *s);

char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strchr(const char *s, int c);

int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);

void mx_strdel(char **str);
char *mx_strdup(const char *str);

char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char *s);

int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strndup(const char *str, size_t n);

char *mx_strnew(const int size);
char **mx_strsplit(const char *s, char c);

char *mx_strstr(const char *haystack, const char *needle);
char *mx_strtrim(const char *str);

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
double mx_sqrt(double x);
int mx_sum_digits(int num);

void mx_swap(void *v1, void *v2, size_t size);

#endif
