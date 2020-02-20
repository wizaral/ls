#include "uls.h"

void mx_error_nodir(char *argum) {
    mx_printstr("uls: ", 2);
    mx_printstr(argum, 2);
    mx_printstr(": No such file or directory\n", 2);
}

void mx_error_usage() {
    mx_printstr(MX_USAGE, 2);
    mx_printchar('\n', 2);
    exit(1);
}

void mx_nelegal(char flag) {
    mx_printstr("uls: illegal option -- ", 2);
    mx_printchar(flag, 2);
    mx_printchar('\n', 2);
    mx_error_usage();
}
