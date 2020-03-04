#include "uls.h"

void mx_bsize(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    char *bsize = mx_itoa(st->st_blksize);
    int bsize_size = mx_strlen(bsize);

    file->bsize = st->st_blksize;
    file->fields.bsize = bsize;
    file->lengths.bsize = bsize_size;
    if (dir->off.bsize < bsize_size)
        dir->off.bsize = bsize_size;
    ++info;
}
