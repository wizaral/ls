#include "uls.h"

char *mx_get_path_name(char *path, size_t plen, char *name, size_t nlen) {
    return mx_strcpy(mx_strcpy(mx_strcpy(mx_strnew(plen + nlen + 1), path) + plen, "/") + 1, name) - 1 - plen;
}
