#include "libmx.h"

int mx_get_char_index(t_cc *str, char c) {
    for (int i = 0; str && str[i]; ++i)
        if (str[i] == c)
            return i;
    return str ? -1 : -2;
}
