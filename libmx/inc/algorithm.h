#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "types.h"
#include "structs.h"

typedef struct s_parametrs {
    void *arr;
    size_t i;
    size_t j;
    size_t left;
    size_t right;
    t_stack stack;
} t_parametrs;

typedef unsigned char t_byte;

typedef struct s_pivot {
    t_byte *temp;
    long long pivot;
} t_pivot;

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

void mx_sort(void *arr, size_t size, size_t bytes, int (*f)(const void *, const void *));
void mx_quicksort(void *arr, size_t size, size_t bytes, size_t (*w)(const void *));

void mx_sort_fast(void *arr, size_t size, size_t bytes, int (*cmp)(const void *, const void *));
void mx_quicksort_fast(void *arr, size_t size, size_t bytes, long long (*w)(const void *));

#endif
