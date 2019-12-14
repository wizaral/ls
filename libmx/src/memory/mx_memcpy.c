#include "libmx.h"

void *mx_memcpy(void *restrict dst, t_cv *restrict src, size_t n) {
    t_uc *udst = dst;
    t_cuc *usrc = src;

    for (size_t i = 0; i < n; ++i)
        udst[i] = usrc[i];
    return (void *)dst;
}
