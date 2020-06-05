#include "uls.h"

int mx_compare_size_r(const void *a, const void *b) {
    const t_file *f1 = a;
    const t_file *f2 = b;

    if (f1->size != f2->size) {
        return f1->size - f2->size;
    }
    return mx_strcmp(f2->fields.name, f1->fields.name);
}
