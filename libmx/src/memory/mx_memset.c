#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    for (uint8_t *ptr = b; len; --len, ++ptr)
        *ptr = c;
    return b;
}
