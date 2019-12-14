#include "libmx.h"

int mx_memcmp(t_cv *s1, t_cv *s2, size_t n) {
    int result = 0;

    if (s1 != s2) {
        t_cuc *us1 = s1;
        t_cuc *us2 = s2;
        t_cuc *end = us1 + n;

        for (; !result && us1 != end; result = *us1++ - *us2++);
    }
    return result;
}
