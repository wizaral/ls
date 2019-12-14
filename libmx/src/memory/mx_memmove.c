#include "libmx.h"

void *mx_memmove(void *dst, t_cv *src, size_t len) {
    // void *temp = malloc(len);
    t_uc temp[len];

    mx_memcpy(temp, src, len);
    mx_memcpy(dst, temp, len);
    // free(temp);
    return dst;
}
