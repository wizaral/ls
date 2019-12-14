#include "libmx.h"

int mx_strncmp(t_cc *s1, t_cc *s2, int n) {
    if (s1 != s2 && n) {
        t_cc *end = s1 + n;
        int result = 0;

        for (; !result && s1 != end && (*s1 || *s2); result = *s1++ - *s2++);
        return result;
    }
    return 0;
}
