#include "libmx.h"

void mx_insert(t_vector *v, t_ull pos, t_cv *item) {
    if (v && item && pos <= v->size) {
        t_ull b = v->bytes;

        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, b * v->cap);
        }
        if (pos < v->size) {
            for (t_ull i = v->size * b; i > pos + b; i -= b)
                mx_memcpy((t_uc *)v->arr + i, (t_uc *)v->arr + i - b, b);
        }
        mx_memcpy((t_uc *)v->arr + pos * b, item, b);
        ++v->size;
    }
}
