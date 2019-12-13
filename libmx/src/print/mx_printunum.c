#include "libmx.h"

static void printnum(t_ull n, const in fd) {
    if (n > 9)
        printunum(n / 10, fd);
    mx_printchar(n % 10 + 48, fd);
}

void mx_printunum(t_ull n, const int fd) {
    if (fd >= 0)
        printnum(n, fd);
}
