#include "libmx.h"

int mx_get_unum_length(uint64_t nbr, uint32_t base) {
    int result = 0;

    for (; nbr; nbr /= base, ++result);
    return result;
}
