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

// #include <time.h>
// #include <stdio.h>

// int compare(const void *a, const void *b) {
//     return *(int *)a - *(int *)b;
// }

// int main() {
//     srand(time(NULL));
//     int size = 1000000000;
//     int *arr1 = malloc(sizeof(int) * size), *arr2 = malloc(sizeof(int) * size);

//     for (int i = 0; i < size; ++i)
//         arr1[i] = rand();

//     memcpy(arr2, arr1, sizeof(int) * size);

//     time_t t1 = time(NULL);
//     qsort(arr1, size, sizeof(int), compare);
//     time_t t2 = time(NULL);

//     printf("%lli\n", t2 - t1);

//     t1 = time(NULL);
//     mx_sort(arr2, size, sizeof(int), compare);
//     t2 = time(NULL);

//     printf("%lli\n", t2 - t1);
//     printf("%i%i\n", mx_checksort(arr1, size, sizeof(int), compare), mx_checksort(arr2, size, sizeof(int), compare));
// }
