#include "libmx.h"

void mx_foreach_vector(t_vector *v, void (*f)(void *)) {
    if (v && v->arr && f) {
        t_ull end = v->size * v->bytes;

        for (t_ull i = 0; i < end; i += v->bytes)
            f((t_uc *)v->arr + i);
}
