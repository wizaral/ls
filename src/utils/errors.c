#include "uls.h"

void mx_wrong_flag(char flag) {
    mx_printstrlen("uls: illegal option -- ", 23, 2);
    mx_printchar(flag, 2);
    mx_printstr("\n" MX_USAGE "\n", 2);
    exit(1);
}

void mx_wrong_argv(t_info *info, const char *av) {
    info->return_val = 1;
    mx_printstrlen("uls: ", 5, 2);
    perror(av);
}
