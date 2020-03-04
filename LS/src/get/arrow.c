#include "uls.h"

void mx_arrow(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    char buff[512];

    readlink(dir->filename, buff, 512);
    file->fields.arrow = mx_strdup(buff);
    ++info;
    ++st;
}
