#include "uls.h"

static inline void usage() {
    mx_printstr(MX_USAGE, 2);
    mx_printchar('\n', 2);
    exit(1);
}

void mx_wrong(char flag) {
    mx_printstrlen("uls: illegal option -- ", 23, 2);
    mx_printchar(flag, 2);
    mx_printchar('\n', 2);
    usage();
}
