#include "libmx.h"

void *mx_memdup(const void *src, size_t n) {
    t_uc *udst = (t_uc *)malloc(n);
    const t_uc *usrc = src;

    for (size_t i = 0; i < n; udst[i] = usrc[i], ++i);
    return udst;
}
