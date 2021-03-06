#include "libmx.h"

void mx_push_backward(t_vector *v, const void *item) {
    if (v && v->arr && item) {
        if (v->size == v->cap) {
            v->cap *= 2;
            v->arr = mx_realloc(v->arr, v->bytes * v->cap);
        }
        mx_memcpy(v->arr + (v->size * v->bytes), item, v->bytes);
        ++v->size;
    }
}
