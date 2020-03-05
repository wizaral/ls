#include "uls.h"

// static inline size_t get_len(t_info *info, t_offset *off) {
//     return off->inode + off->bsize + off->links + off->user
//         + off->grp + off->flags + off->size + (off->inode > 0)
//         + (off->bsize > 0) + (off->user > 0) + (off->user > 0)
//         + (off->flags > 0) + 12 + 1 + 2 + 1
//         + (info->get.time == mx_time_full ? 21 : 13);
// }

// static void create_str(t_offset *off, char *str,
//                        t_printable *print, t_lengths *len) {
//     int pos = 0;

//     mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
//     pos += off->inode + (off->inode > 0);
//     mx_memcpy(str + pos + off->bsize - len->bsize, print->bsize, len->bsize);
//     pos += off->bsize + (off->bsize > 0);
//     mx_memcpy(str + pos, print->access, 12);
//     pos += 12;
//     mx_memcpy(str + pos + off->links - len->links, print->links, len->links);
//     pos += off->links + 1;
//     mx_memcpy(str + pos + off->user - len->user, print->user, len->user);
//     pos += off->user + (off->user > 0) + (off->user > 0);
//     mx_memcpy(str + pos + off->grp - len->grp, print->grp, len->grp);
//     pos += off->grp + 2;
//     mx_memcpy(str + pos + off->flags - len->flags, print->flags, len->flags);
//     pos += off->flags + (off->flags > 0);
//     mx_memcpy(str + pos + off->size - len->size, print->size, len->size);
//     pos += off->size + 1;
//     mx_memcpy(str + pos, print->time, len->time);
// }

// static void print(t_info *info, t_dir *dir, t_file *file) {
//     size_t len = get_len(info, &dir->off);
//     char str[len];

//     mx_memset(str, ' ', len);
//     create_str(&dir->off, str, &file->fields, &file->lengths);
//     mx_printstrlen(str, len, 1);
//     info->print_name(file);
//     mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
//     mx_printstrlen(file->fields.arrow, file->lengths.arrow, 1);
//     mx_printchar('\n', 1);
//     mx_printstrlen(file->fields.attr, file->lengths.attr, 1);
//     mx_printstrlen(file->fields.acl, file->lengths.acl, 1);
// }

void mx_write_l(t_info *info, t_dir *dir) {
    // info->foreach(info, dir, print);
    ++info;
    ++dir;
}
