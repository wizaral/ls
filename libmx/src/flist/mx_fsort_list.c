#include "libmx.h"

t_flist *mx_fsort_list(t_flist *list, int (*cmp)(t_cv *, t_cv *)) {
    // mergesort lol

    return list && cmp ? list : NULL;
}
