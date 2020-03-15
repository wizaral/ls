#include "libmx.h"

static void sort(uint8_t *left, uint8_t *right, size_t bytes,
                 int (*cmp)(const void *, const void *)) {
    uint8_t *low = left;
    uint8_t *high = right;
    size_t temp = ((right - left) / bytes) / 2;
    uint8_t pivot[bytes];

    mx_memcpy(pivot, left + temp * bytes, bytes);
    while (low < high) {
        for (; cmp(low, pivot) < 0; low += bytes);
        for (; cmp(high, pivot) > 0; high -= bytes);
        if (low <= high) {
            mx_swap(low, high, bytes);
            low += bytes;
            high -= bytes;
        }
    }
    if (left < (high -= (high == right) * bytes))
        sort(left, high, bytes, cmp);
    if ((low += (low == left) * bytes) < right)
        sort(low, right, bytes, cmp);
}

void mx_sort(void *arr, size_t size, size_t bytes,
             int (*cmp)(const void *, const void *)) {
    if (arr && size > 1 && bytes > 0 && cmp)
        sort(arr, (uint8_t *)arr + ((size - 1) * bytes), bytes, cmp);
}
