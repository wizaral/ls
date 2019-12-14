#include "libmx.h"

void mx_printstr(t_cc *s, const int fd) {
    if (fd >= 0)
        write(fd, s, mx_strlen(s));
}
