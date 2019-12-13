#include "libmx.h"

t_ull mx_sigma(t_ull n) {
    t_ull result = 0;

    if (n < 6074001000)
        for (t_ull i = 1; i <= n; ++i)
            result += i;
    return result;
}
