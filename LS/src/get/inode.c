#include "uls.h"

void mx_get_inode(t_dir *dir, t_file *file, t_stat *st) {
    int ino_len = mx_get_num_length(st->st_ino, 10);

    file->inode = st->st_ino;
    file->fields.inode = mx_itoa(st->st_ino);
    file->lengths.inode = ino_len;
    dir->off.inode = ino_len;
}
