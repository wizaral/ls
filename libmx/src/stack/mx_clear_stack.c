#include "libmx.h"

void mx_clear_stack(t_stack *st) {
    if (st && st->size) {
        st->cap = MX_STACK_DEFAULT_SIZE;
        st->size = 0;
        if (MX_MALLOC_SIZE(st->arr))
            free(st->arr);
        st->arr = malloc(st->bytes * MX_STACK_DEFAULT_SIZE);
    }
}
