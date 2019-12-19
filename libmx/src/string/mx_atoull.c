#include "libmx.h"

t_ull mx_atoull(t_cc *str) {
    t_ull sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+')
        ++str;
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sum;
}
