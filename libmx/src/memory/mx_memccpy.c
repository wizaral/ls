#include "libmx.h"

void *mx_memccpy(void *restrict dst, t_cv *restrict src, int c, size_t n) {
    if (dst && src && n) {
        t_uc *udst = dst;
        t_cuc *usrc = src;

        for (size_t i = 0; i < n; ++i) {
            udst[i] = usrc[i];
            if (usrc[i] == c)
                return (void *)(udst + i + 1);
        }
    }
    return NULL;
}
