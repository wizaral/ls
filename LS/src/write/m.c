#include "uls.h"

static void create_str(t_offset *off, char *str,
                       t_printable *print, t_lengths *len) {
    int pos = 0;

    mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
    pos += off->inode + (off->inode > 0);
    mx_memcpy(str + pos + off->bsize - len->bsize, print->bsize, len->bsize);
    pos += off->bsize + (off->bsize > 0);
}

// static void write_data(t_dir *dir, t_file *dt, char *str, int len) {
//     // printf("%zu = %zu\n", dir->off.x, dir->off.width);
//     create_str(&dir->off, str, &dt->fields, &dt->lengths);
//     mx_printstrlen(str, len, 1);
// }

// static void write_data_name(t_info *info, t_dir *dir, t_file *dt, bool newline) {
//     info->print_name(dt);
//     mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
//     if (newline == false)
//         mx_printstrlen(", ", 2, 1);
//     else
//         mx_printstrlen("\n", 1, 1);
//         dir++;
// }

static void calc_x(t_info *info, t_file *dt, int *len, t_dir *dir) {
    dir->off.x += (*len = dt->lengths.name
        + dt->lengths.inode + (dt->lengths.inode != 0)
        + dt->lengths.bsize + (dt->lengths.bsize != 0)
        + (info->get.suffix != mx_dummy) + 2);
}

// void mx_write_m(t_info *info, t_dir *dir) {
//     t_file *dt = NULL;
//     int len = dir->off.x = 0;
//     size_t len_file_additions = dir->off.inode + dir->off.bsize
//                               + (dir->off.inode > 0) + (dir->off.bsize > 0);
//     char str[len_file_additions];

//     dir->off.width = mx_winsize(info);
//     for (size_t i = 0; i < dir->array.size; ++i) {
//         dt = mx_at(&dir->array, i);
//         mx_memset(str, ' ', len_file_additions);
//         calc_x(info, dt, &len, dir);
        
//         write_data(dir, dt, str, len_file_additions);
//         write_data_name(info, dir, dt, i + 1 == dir->array.size);
//         mx_printstrlen("\n", dir->off.x > dir->off.width, 1);
//         dir->off.x > dir->off.width ? (dir->off.x = len) : (dir->off.x = dir->off.x);
//     }
// }

void print(t_info *info, t_dir *dir, t_file *dt, int len) {
    mx_printstrlen(", ", 2, 1);
    if (dir->off.x +
        dt->lengths.bsize + (dt->lengths.bsize != 0)
      + dt->lengths.inode + (dt->lengths.inode != 0)
      + 2 > dir->off.width) {
        mx_printstrlen("\n", 1, 1);
        dir->off.x = len;
    }
    info++;
    dt++;
}

void mx_write_m(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    int len = dir->off.x = 0;
    size_t len_addition = dir->off.inode + dir->off.bsize
                        + (dir->off.inode > 0) + (dir->off.bsize > 0);
    char str[len_addition];

    dir->off.width = mx_winsize(info);
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_memset(str, ' ', len_addition);
        calc_x(info, dt, &len, dir);
        create_str(&dir->off, str, &dt->fields, &dt->lengths);
        mx_printstrlen(str, len_addition, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
        if (i + 1 != dir->array.size)
            print(info, dir, dt, len);
        else
            mx_printstrlen("\n", 1, 1);
    }
}
