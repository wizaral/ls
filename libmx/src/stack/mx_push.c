#include "libmx.h"

void mx_push(t_stack *st, void *item) {
    if (st && st->arr && item) {
        if (st->size == st->cap) {
            st->cap *= 2;
            st->arr = mx_realloc(st->arr, st->cap * st->bytes);
        }
        mx_memcpy(st->arr + (st->size * st->bytes), item, st->bytes);
        ++st->size;
    }
}
