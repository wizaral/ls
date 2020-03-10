#include "uls.h"

void mx_arrow(t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISLNK(st->st_mode)) {
        size_t size = MX_MIN(st->st_size, 1024, int64_t) + 1;
        char buff[size];
        ssize_t len = readlink(dir->filename, buff, size);

        if (len != -1) {
            buff[file->size] = '\0';
            file->lengths.arrow = file->size + 4;
            file->fields.arrow = (char *)mx_memcpy((char *)mx_memcpy(
                malloc(file->size + 5), " -> ", 4) + 4, buff, file->size + 1) - 4;
        }
    }
}
