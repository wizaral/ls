#include "libmx.h"

t_ull mx_binary_search(t_cv *key, t_cvector *v, int (*cmp)(t_cv *, t_cv *)) {
    t_ull left = 0;
    t_ull right = v ? v->size - 1 : 0;
    t_ull middle = 0;
    t_ull result;

    if (v && v->size && v->arr && key && cmp) {
        while (left <= right) {
            middle = left + (right - left) / 2;
            result = cmp(key, (t_uc *)v->arr + (middle * v->bytes));
            if (result > 0)
                left = middle + 1;
            else if (result < 0)
                right = middle - 1;
            else
                return middle;
        }
    }
    return 0;
}
