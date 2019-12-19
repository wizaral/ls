#include "libmx.h"

t_ull mx_linear_search(t_cv *key, t_cvector *v, int (*cmp)(t_cv *, t_cv *)) {
    t_ull bytes = v->bytes;
    t_ull end = (v->size - 1) * bytes;

    for (t_ull i = 0; i < end; i += bytes)
        if (cmp(key, (t_uc *)v->arr + i) == 0)
            return i;
    return 0;
}
