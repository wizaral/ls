#include "libmx.h"

void mx_insert(t_vector *v, size_t pos, const void *item) {
    if (v && item && pos <= v->size) {
        uint8_t *ppos = v->arr + pos * v->bytes;

        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, v->bytes * v->cap);
        }
        if (pos < v->size)
            mx_memmove(v->arr + pos + 1, v->arr + pos,
                        (v->size - pos - 1) * v->bytes);
        mx_memcpy(ppos, item, v->bytes);
        ++v->size;
    }
}
