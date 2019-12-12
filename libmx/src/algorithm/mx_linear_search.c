#include "libmx.h"

t_ll mx_linear_search(t_cv *key, const t_vector *v,
    int (*cmp)(t_cv *, t_cv *))
{
    for (t_ll i = 0, end = (v->size - 1) * v->bytes; i < end; i += v->bytes)
        if (cmp(key, (t_uc *)v->arr + i) == 0)
            return i;
    return -1;
}
