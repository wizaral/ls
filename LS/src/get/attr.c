#include "uls.h"

void mx_get_attr(t_dir *dir, t_file *file, struct stat *st) {
    char buff[512];
    char *path = mx_strjoin(dir->name, "/");

    mx_strcat(path, file->fields.name);
    listxattr(path, buff, 512, XATTR_SHOWCOMPRESSION);
    file->fields.attr = mx_memdup(buff, 512);
    st++;
}
