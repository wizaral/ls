#include "uls.h"

void mx_arrow(t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISLNK(st->st_mode)) {
        size_t size = st->st_size ? MX_MIN(st->st_size, 255, int64_t) : 255;
        char buff[size + 1];
        ssize_t len = readlink(dir->filename, buff, size);

        if (len != -1) {
            buff[len] = '\0';
            file->lengths.arrow = len + 4;
            file->fields.arrow = (char *)mx_memcpy((char *)mx_memcpy(
                malloc(len + 5), " -> ", 4) + 4, buff, len + 1) - 4;
        }
    }
}
