#include "libmx.h"

char *mx_strdup(const char *str) {
    char *ptr = mx_strnew(mx_strlen(str), '\0');

    return ptr ? mx_strcpy(ptr, str) : NULL;
}
