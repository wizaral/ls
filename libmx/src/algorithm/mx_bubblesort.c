#include "libmx.h"

void mx_bubblesort(void *arr, t_cs size, t_cs bytes,
    int (*cmp)(t_cv *, t_cv *))
{
    for (t_ull i = 0, swaps = 0; arr && i < size; i += bytes, swaps = 0) {
        for (t_ull j = 0; j < size - i - 1; j += bytes)
            if (cmp((t_uc *)arr + j, (t_uc *)arr + j + bytes) > 0) {
                mx_swap((t_uc *)arr + j, (t_uc *)arr + j + bytes, bytes);
                ++swaps;
            }
        if (swaps == 0)
            break;
    }
}
