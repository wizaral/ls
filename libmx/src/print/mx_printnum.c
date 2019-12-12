#include "libmx.h"

static void printnum(t_ll n, const int fd) {
    if (n > 9)
        printnum(n / 10, fd);
    mx_printchar(n % 10 + 48, fd);
}

void mx_printnum(t_ll n, const int fd) {
    const t_ll min = -__LONG_LONG_MAX__ - 1LL;

    if (fd >= 0) {
        if (n == min) {
            write(fd, "−9223372036854775808", 20);
            return;
        }
        if (n < 0) {
            mx_printchar('-', fd);
            n *= -1;
        }
        printnum(n, fd);
    }
}
