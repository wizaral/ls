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

// #include <time.h>
// #include <stdio.h>

// int compare(const void *a, const void *b) {
//     return *(int *)a - *(int *)b;
// }

// int64_t weight(const void *a) {
//     return *(int *)a;
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
//     mx_quicksort(arr2, size, sizeof(int), weight);
//     t2 = time(NULL);

//     printf("%lli\n", t2 - t1);
//     printf("%i%i\n", mx_checksort(arr1, size, sizeof(int), compare), mx_checksort(arr2, size, sizeof(int), compare));
// }
