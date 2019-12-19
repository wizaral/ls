#include "libmx.h"

void mx_sort(void *arr, size_t size, size_t bytes, int (*f)(t_cv *, t_cv *)) {
    if (arr && size > 0 && bytes > 0 && f) {
        t_ull i = 0;
        t_ull j = (size - 1) * bytes;
        t_uc pivot[bytes];

        mx_memcpy(pivot, ((t_uc *)arr + (size / 2) * bytes), bytes);
        while (i < j) {
            for (; f((t_uc *)arr + i, pivot) < 0; i += bytes);
            for (; f((t_uc *)arr + j, pivot) > 0; j -= bytes);
            if (i <= j) {
                mx_swap((t_uc *)arr + i, (t_uc *)arr + j, bytes);
                i += bytes, j -= bytes;
            }
        }
        if (i / bytes < size - 1)
            mx_sort((t_uc *)arr + i, size - i / bytes, bytes, f);
        if (0 < j / bytes)
            mx_sort(arr, j / bytes + 1, bytes, f);
    }
}
