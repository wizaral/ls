#include "libmx.h"

void mx_print_strarr(t_cc **arr, t_cc *delim, const int fd) {
    if (arr && *arr && delim && fd >= 0) {
        for (mx_printstr(*arr, fd); *++arr; mx_printstr(*arr, fd))
            mx_printstr(delim, fd);
        mx_printchar('\n', fd);
    }
}
