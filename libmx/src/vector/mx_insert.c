#include "libmx.h"

void mx_insert(t_vector *v, t_ull pos, const void *item) {
    if (v && item && pos <= v->size) {
        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, v->cap);
        }

        if (pos < v->size)
            for (t_ull b = v->bytes, i = v->size * b; i > pos; i -= b)
                mx_memcpy((t_uc *)v->arr + i, (t_uc *)v->arr + i - b, b);

        mx_memcpy((t_uc *)v->arr + pos * v->bytes, item, v->bytes);
        ++v->size;
    }
}
