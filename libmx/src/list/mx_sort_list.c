#include "libmx.h"

t_list *mx_sort_list(t_list *list, int (*cmp)(t_cv *, t_cv *)) {
// mergesort lol

    return list && cmp ? list : NULL;
}
