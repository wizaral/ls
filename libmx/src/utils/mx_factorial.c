#include "libmx.h"

t_ull mx_factorial(t_ull n) {
    t_ull result = 1;

    if (n > 20)
        return 0;

    for (t_ull i = 1; i <= n; ++i)
        result *= i;
    return result;
}
