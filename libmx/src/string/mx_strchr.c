#include "libmx.h"

char *mx_strchr(t_cc *s, int c) {
    for (int i = 0; s[i]; ++i)
        if (s[i] == c)
            return (char *)(s + i);
    return NULL;
}
