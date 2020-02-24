#include "uls.h"

int mx_compare_time(const void *a, const void *b) {
    t_file *f1 = a;
    t_file *f2 = b;

    if (f1->time.tv_sec != f2->time.tv_sec)
        return f1->time.tv_sec - f2->time.tv_sec;   // maybe unsigned
    if (f1->time.tv_nsec != f2->time.tv_nsec)
        return f1->time.tv_nsec - f2->time.tv_nsec; // maybe unsigned
    return mx_strcmp(f1->fields.name, f2->fields.name);
}
