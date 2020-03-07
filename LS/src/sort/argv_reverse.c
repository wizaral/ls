#include "uls.h"

int mx_compare_argv_r(const void *a, const void *b) {
    return mx_strcmp(*(char **)b, *(char **)a);
}
