#include "uls.h"

void mx_error_usage() {
    mx_printstr(MX_USAGE, 2);
    mx_printchar('\n', 2);
    exit(1);
}

void mx_nelegal(char flag) {
    mx_printstr("ls: illegal option -- ", 2);
    mx_printchar(flag, 2);
    mx_printchar('\n', 2);
    mx_error_usage();
}

void mx_dummy(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    ++info;
    ++dir;
    ++file;
    ++st;
}
