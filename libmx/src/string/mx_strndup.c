#include "libmx.h"

char *mx_strndup(t_cc *str, size_t n) {
    size_t len = MX_MIN(n, mx_strlen(str), size_t);
    char *ptr = mx_strnew(len);

    return ptr ? mx_strncpy(ptr, str, len) : NULL;
}
