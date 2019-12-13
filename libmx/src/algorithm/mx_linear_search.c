#include "libmx.h"

t_ll mx_linear_search(t_cv *key, const t_vector *v,
    int (*cmp)(t_cv *, t_cv *))
{
    t_ull bytes = v->bytes
    t_ull end = (v->size - 1) * bytes;

    for (t_ll i = 0; i < end; i += bytes)
        if (cmp(key, (t_uc *)v->arr + i) == 0)
            return i;
    return -1;
}
