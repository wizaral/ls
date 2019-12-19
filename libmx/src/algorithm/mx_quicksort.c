#include "libmx.h"

void mx_quicksort(void *arr, size_t size, size_t bytes, t_ull (*w)(t_cv *)) {
    if (arr && size > 0 && bytes > 0 && w) {
        t_ull i = 0;
        t_ull j = (size - 1) * bytes;
        t_uc temp[bytes];
        t_ull pivot = w(mx_memcpy(temp,
        ((t_uc *)arr + (size / 2) * bytes), bytes));

        while (i < j) {
            for (; w((t_uc *)arr + i) < pivot; i += bytes);
            for (; w((t_uc *)arr + j) > pivot; j -= bytes);
            if (i <= j) {
                mx_swap((t_uc *)arr + i, (t_uc *)arr + j, bytes);
                i += bytes, j -= bytes;
            }
        }
        if (i / bytes < size - 1)
            mx_quicksort((t_uc *)arr + i, size - i / bytes, bytes, w);
        if (0 < j / bytes)
            mx_quicksort(arr, j / bytes + 1, bytes, w);
    }
}
