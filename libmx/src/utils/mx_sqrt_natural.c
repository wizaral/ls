#include "libmx.h"

t_ull mx_sqrt_natural(t_ull x) {
    t_ull left = 0;
    t_ull right = x;
    t_ull middle = 0;
    t_ull power;

    while (left <= right) {
        middle = left + (right - left) / 2;
        power = middle * middle;

        if (power > x)
            right = middle - 1;
        else if (power < x)
            left = middle + 1;
        else
            return middle;
    }
    return 0;
}
