#include "libmx.h"

void *mx_get_back(t_vector *v) {
    return v && v->arr && v->size
    ? (t_uc *)v->arr + (v->bytes * (v->size - 1))
    : NULL;
}
