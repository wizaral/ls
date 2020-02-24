#include "uls.h"

int mx_compare_size(const void *a, const void *b) {
    t_file *f1 = a;
    t_file *f2 = b;

    if (f1->size != f2->size)
        return f1->size - f2->size;                     // maybe unsigned
    return mx_strcmp(f1->fields.name, f2->fields.name);
}
