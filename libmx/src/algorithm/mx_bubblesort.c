#include "libmx.h"

void mx_bubblesort(void *arr, size_t size, size_t bytes,
    int (*cmp)(t_cv *, t_cv *))
{
    if (arr && size && bytes && cmp)
        for (t_ull i = 0, swaps = 0; i < size; i += bytes, swaps = 0) {
            for (t_ull j = 1; j < size - i; j += bytes)
                if (cmp((t_uc *)arr + j - bytes, (t_uc *)arr + j) > 0) {
                    mx_swap((t_uc *)arr + j - bytes, (t_uc *)arr + j, bytes);
                    ++swaps;
                }
            if (swaps == 0)
                break;
        }
}
