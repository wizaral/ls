#include "libmx.h"

static void sort(uint8_t *left, uint8_t *right, size_t bytes,
                 int64_t (*wgt)(const void *)) {
    uint8_t *low = left;
    uint8_t *high = right;
    int64_t pivot = wgt(left + (((right - left) / bytes) / 2) * bytes);

    while (low < high) {
        for (; wgt(low) < pivot; low += bytes);
        for (; wgt(high) > pivot; high -= bytes);
        if (low <= high) {
            mx_swap(low, high, bytes);
            low += bytes;
            high -= bytes;
        }
    }
    if (left < (high -= (high == right) * bytes))
        sort(left, high, bytes, wgt);
    if ((low += (low == left) * bytes) < right)
        sort(low, right, bytes, wgt);
}

void mx_quicksort(void *arr, size_t size, size_t bytes,
                  int64_t (*wgt)(const void *)) {
    if (arr && size > 1 && bytes > 0 && wgt)
        sort(arr, (uint8_t *)arr + ((size - 1) * bytes), bytes, wgt);
}
