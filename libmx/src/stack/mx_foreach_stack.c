#include "libmx.h"

void mx_foreach_stack(t_stack *st, void (*f)(void *)) {
    if (st && st->arr && f) {
        t_ull end = st->size * st->bytes;
        for (t_ull i = 0; i < end; i += st->bytes)
            f((t_uc *)st->arr + i);
    }
}
