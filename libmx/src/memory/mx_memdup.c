#include "libmx.h"

void *mx_memdup(t_cv *src, size_t n) {
    t_uc *udst = (t_uc *)malloc(n);
    t_cuc *usrc = src;

    for (size_t i = 0; i < n; ++i)
        udst[i] = usrc[i];
    return udst;
}
