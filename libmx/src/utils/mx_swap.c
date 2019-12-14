#include "libmx.h"

void mx_swap(void *v1, void *v2, const size_t size) {
    if (v1 && v2 && v1 != v2) {
        t_uc temp[size];

        mx_memcpy(temp, v1, size);
        mx_memcpy(v1, v2, size);
        mx_memcpy(v2, temp, size);
    }
}
