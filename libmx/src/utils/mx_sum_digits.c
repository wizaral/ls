#include "libmx.h"

int mx_sum_digits(t_ull num) {
    int sum = 0;

    for (; num; sum += num % 10, num /= 10);
    return sum;
}
