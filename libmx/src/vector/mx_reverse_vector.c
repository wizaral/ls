#include "libmx.h"

void mx_reverse_vector(t_vector *v) {
    if (v && v->size && v->arr) {
        t_ull i = 0;
        t_ull j = (v->size - 1) * v->bytes;

        for (t_ull b = v->bytes; i < j; i += b, j -= b)
            mx_swap((t_uc *)v->arr + i, (t_uc *)v->arr + j, b);
    }
}
