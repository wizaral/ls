#include "uls.h"

static inline size_t get_len(t_offset *off) {
    return off->inode + off->bsize + (off->inode > 0) + (off->bsize > 0);
}

static void create_str(t_offset *off, char *str,
                       t_printable *print, t_lengths *len) {
    int pos = 0;

    mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
    pos += off->inode + (off->inode > 0);
    mx_memcpy(str + pos + off->bsize - len->bsize, print->bsize, len->bsize);
    pos += off->bsize + (off->bsize > 0);
}

void mx_write_1(t_info *info, t_dir *dir) {
    size_t len = get_len(&dir->off);
    char str[len];
    t_file *file;

    for (size_t i = 0; i < dir->array.size; ++i) {
        mx_memset(str, ' ', len);
        file = mx_at(&dir->array, i);
        create_str(&dir->off, str, &file->fields, &file->lengths);
        mx_printstrlen(str, len, 1);
        info->print_name(file);
        mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
        mx_printchar('\n', 1);
    }
}
