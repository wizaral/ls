#include "uls.h"

void mx_write_1(t_info *info, t_dir *dir) {
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];
    t_file *file;

    for (size_t i = 0; i < dir->array.size; ++i) {
        mx_memset(str, ' ', len);
        file = mx_at(&dir->array, i);
        mx_make_inode_bsize(&dir->off, str, &file->fields, &file->lengths);
        mx_printstrlen(str, len, 1);
        info->print_name(file);
        mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
        mx_printchar('\n', 1);
    }
}
