#include "libmx.h"

void mx_reverse_vector(t_vector *v) {
    t_ull i = 0;

    if (v && v->size && v->arr)
        for (t_ull b = v->bytes, j = (v->size - 1) * b; i < j; i += b, j -= b)
            mx_swap((t_uc *)v->arr + i, (t_uc *)v->arr + j, b);
}
