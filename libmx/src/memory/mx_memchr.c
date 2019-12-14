#include "libmx.h"

void *mx_memchr(t_cv *s, int c, size_t n) {
    if (s && n) {
        t_cuc *us = s;

        for (size_t i = 0; i < n; ++i)
            if (us[i] == c)
                return (void *)(us + i);
    }
    return NULL;
}
