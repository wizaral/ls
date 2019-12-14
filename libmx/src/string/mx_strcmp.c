#include "libmx.h"

int mx_strcmp(t_cc *s1, t_cc *s2) {
    if (s1 != s2) {
        int i = 0;

        for (; s1[i] == s2[i] && s1[i] && s2[i]; ++i);
        return s1[i] - s2[i];
    }
    return 0;
}
