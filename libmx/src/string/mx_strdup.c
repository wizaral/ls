#include "libmx.h"

char *mx_strdup(t_cc *str) {
    char *ptr = mx_strnew(mx_strlen(str));

    return ptr ? mx_strcpy(ptr, str) : NULL;
}
