#include "uls.h"

int mx_compare_argv(const void *a, const void *b) {
    return mx_strcmp(*(char **)a, *(char **)b);
}
