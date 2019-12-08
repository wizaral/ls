#include "libmx.h"

int mx_sqrt_natural(int x) {
    t_ull left = 0;
    t_ull right = x > 0 ? x : 0;
    t_ull middle = 0;
    t_ull power;

    while (left <= right) {
        middle = left + (right - left) / 2;
        power = middle * middle;

        if (power == (t_ull)x)
            return middle;
        else if (power > (t_ull)x)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return 0;
}
