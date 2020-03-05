#include "uls.h"

int mx_compare_ascii_r(const void *a, const void *b) {
    return mx_strcmp(((t_file *)b)->fields.name, ((t_file *)a)->fields.name);
}
