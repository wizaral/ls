#include "libmx.h"

static inline char *make_dec(int64_t num, int length) {
    char *dec = mx_strnew(length);

    *dec = num < 0 ? '-' : '\0';
    for (int j = length - 1; j >= (num <= 0); --j, num /= 10)
        dec[j] = MX_ABS(num % 10) + 48;
    return dec;
}

char *mx_lltoa(int64_t nbr) {
    return nbr ? make_dec(nbr, mx_numlen(nbr, 10)) : mx_strdup("0");
}
