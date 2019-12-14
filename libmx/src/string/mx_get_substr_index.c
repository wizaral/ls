#include "libmx.h"

int mx_get_substr_index(t_cc *str, t_cc *sub) {
    if (str && sub) {
        int len1 = mx_strlen(str);
        int len2 = mx_strlen(sub);

        if (len1 >= len2)
            for (t_cc *copy = str; (str = mx_strchr(str, *sub)); ++str)
                if (mx_strncmp(str, sub, len2) == 0)
                    return str - copy;
        return -1;
    }
    return -2;
}
