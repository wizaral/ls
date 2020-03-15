#include "uls.h"

// static void minor_major(t_dir *dir, t_file *file, t_stat *st) {
//     // int size_len = mx_numlen(st->st_size, 10);

//     // file->fields.size = mx_lltoa(st->st_size);
//     // file->lengths.size = size_len;
//     // if (dir->off.size < size_len)
//     //     dir->off.size = size_len;
//     ++dir;
//     ++file;
//     ++st;
// }

void mx_size_b(t_dir *dir, t_file *file, t_stat *st) {
    int size_len = mx_numlen(st->st_size, 10);
    char *str = malloc(size_len + 1);

    file->fields.size = mx_lltoa_s(st->st_size, str, size_len);
    file->fields.size[size_len] = ' ';
    file->lengths.size = size_len + 1;
    if (dir->off.size < size_len)
        dir->off.size = size_len;
}
