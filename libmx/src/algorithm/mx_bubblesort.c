#include "libmx.h"

void mx_bubblesort(void *arr, size_t size, size_t bytes,
    int (*cmp)(t_cv *, t_cv *))
{
    if (arr && size && bytes && cmp) {
        t_ull swaps = 0;

        for (t_ull i = (size - 1) * bytes; i > 0; i -= bytes, swaps = 0) {
            for (t_ull j = 0; j < i; j += bytes)
                if (cmp((t_uc *)arr + j, (t_uc *)arr + (j + bytes)) > 0) {
                    mx_swap((t_uc *)arr + j, (t_uc *)arr + (j + bytes), bytes);
                    ++swaps;
                }
            if (swaps == 0)
                break;
        }
    }
}
