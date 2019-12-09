#include "libmx.h"

void *mx_at(t_vector *v, t_ull pos) {
    return v && v->arr && pos < v->size
    ? (t_uc *)v->arr + (v->bytes * pos)
    : NULL;
}
