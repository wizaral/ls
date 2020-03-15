#include "uls.h"

void mx_nototal(t_info *info, t_dir *dir) {
    ++info;
    ++dir;
}

void mx_total(t_info *info, t_dir *dir) {
    if (dir->array.size) {
        mx_printstrlen("total ", 6, 1);
        mx_printunum(dir->total, 1);
        mx_printchar('\n', 1);
    }
    ++info;
}
