#include "libmx.h"

t_ull mx_strlen(t_cc *s) {
    t_ull len = 0;

    for (; s[len]; ++len);
    return len;
}
