#include "libmx.h"

char *mx_strcpy(char *dst, t_cc *src) {
    for (int i = 0; src[i++]; dst[i] = src[i]);
    return (*dst = *src, dst);
}
