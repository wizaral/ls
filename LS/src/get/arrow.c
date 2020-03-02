#include "uls.h"

void mx_arrow(t_dir *dir, t_file *file, t_stat *st) {
    char buff[512];
    char *path = mx_strjoin(dir->name, "/");

    mx_strcat(path, dir->file->d_name);
    readlink(path, buff, 512);
    file->fields.arrow = mx_strdup(buff);
    ++st;
}
