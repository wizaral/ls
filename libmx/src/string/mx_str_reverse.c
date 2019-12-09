#include "libmx.h"

void mx_str_reverse(char *s) {
    for (t_ull i = 0, j = s ? mx_strlen(s) - 1 : 0; s && i < j; ++i, --j)
        mx_swap(s + i, s + j, sizeof(char));
}
