#include "uls.h"

// static inline size_t get_len(t_offset *off) {
//     return off->inode + off->bsize + (off->inode > 0) + (off->bsize > 0);
// }

// static void create_str(t_offset *off, char *str,
//                        t_printable *print, t_lengths *len) {
//     int pos = 0;

//     if (print->inode) {
//         mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
//         pos += off->inode + (off->inode > 0);
//     }
//     if (print->bsize) {
//         mx_memcpy(str + pos + off->bsize - len->bsize, print->bsize, len->bsize);
//         pos += off->bsize + (off->bsize > 0);
//     }
// }

// static void print(t_info *info, t_dir *dir, t_file *file) {
//     size_t len = get_len(&dir->off);
//     char str[len];

//     mx_memset(str, ' ', len);
//     create_str(&dir->off, str, &file->fields, &file->lengths);
//     mx_printstrlen(str, len, 1);
//     info->print_name(file);
//     mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
//     mx_printchar('\n', 1);
// }

void mx_write_1(t_info *info, t_dir *dir) {
    // info->foreach(info, dir, print);
    ++info;
    ++dir;
}
