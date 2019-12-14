#include "libmx.h"

void *mx_memmem(t_cv *big, size_t big_len, t_cv *little, size_t little_len) {
    t_cuc *ubig = big;

    if (big_len > little_len && little_len)
        while (big_len >= little_len && (mx_memcmp(ubig, little, little_len)))
            ++ubig, --big_len;

    return big_len >= little_len && little_len ? (void *)ubig : NULL;
}
