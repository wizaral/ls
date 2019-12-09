#include "libmx.h"

t_ll mx_binary_search(t_cv *key, t_vector *v, int (*cmp)(t_cv *, t_cv *)) {
    t_ll left = 0;
    t_ll right = v->size - 1;
    t_ll middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (cmp(key, (t_uc *)v->arr + middle * v->bytes) > 0)
            left = middle + 1;
        else if (cmp(key, (t_uc *)v->arr + middle * v->bytes) < 0)
            right = middle - 1;
        else
            return middle;
    }
    return -1;
}
