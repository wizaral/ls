#include "uls.h"

void mx_inode(t_dir *dir, t_file *file, t_stat *st) {
    int ino_len = mx_numlen(st->st_ino, 10);

    file->fields.inode = mx_lltoa(st->st_ino);
    file->lengths.inode = ino_len;
    if (dir->off.inode < ino_len)
        dir->off.inode = ino_len;
}
