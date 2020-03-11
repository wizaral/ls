#include "uls.h"

static inline size_t get_len(t_info *info, t_offset *off) {
    return off->inode + (off->inode > 0) + off->bsize + (off->bsize > 0) + 12
            + off->links + 1 + off->user + (off->user > 0) + (off->user > 0)
            + off->grp + (off->grp > 0) + (off->grp > 0)
            + off->size + 1
            + (info->get.time == mx_time_full ? 21 : 13)
            + (off->user == 0 && off->grp == 0)
            + (off->user == 0 && off->grp == 0);
}

static void create_str(t_offset *off, char *str,
                       t_printable *print, t_lengths *len) {
    int pos = 0;

    mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
    pos += off->inode + (off->inode > 0);
    mx_memcpy(str + pos + off->bsize - len->bsize, print->bsize, len->bsize);
    pos += off->bsize + (off->bsize > 0);
    mx_memcpy(str + pos, print->access, 12);
    pos += 12;
    mx_memcpy(str + pos + off->links - len->links, print->links, len->links);
    pos += off->links + 1;
    mx_memcpy(str + pos, print->user, len->user);
    pos += off->user + (off->user > 0) + (off->user > 0);
    mx_memcpy(str + pos, print->grp, len->grp);
    pos += off->grp + (off->grp > 0) + (off->user == 0 && off->grp == 0)
            + (off->grp > 0) + (off->user == 0 && off->grp == 0);
    mx_memcpy(str + pos + off->size - len->size, print->size, len->size);
    pos += off->size + 1;
    mx_memcpy(str + pos, print->time, len->time);
}

void mx_write_l(t_info *info, t_dir *dir) {
    size_t len = get_len(info, &dir->off);
    char str[len];
    t_file *file;

    for (size_t i = 0; i < dir->array.size; ++i) {
        mx_memset(str, ' ', len);
        file = mx_at(&dir->array, i);
        create_str(&dir->off, str, &file->fields, &file->lengths);
        mx_printstrlen(str, len, 1);
        info->print_name(file);
        mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
        mx_printstrlen(file->fields.arrow, file->lengths.arrow, 1);
        mx_printchar('\n', 1);
    }
}
