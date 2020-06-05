#include "uls.h"

static inline  void print_n_spaces(int spaces) {
    for (int i = 0; i < spaces; ++i)
        mx_printchar(' ', 1);
}

static void print_spaces(size_t full_len, size_t cfull_len, t_offset *of) {
    if (of->width > of->x + full_len + full_len) {
        of->x += full_len + 2;
        print_n_spaces(full_len - cfull_len + 1);
    }
    else {
        mx_printchar('\n', 1);
        of->x = 0;
    }
}

void mx_write_xG(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];

    dir->off.width = mx_winsize(info);
    dir->off.x = 0;
    dir->off.name_tabs = mx_get_data_len(info, dir, dt, true) + 1;
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_memset(str, ' ', len);
        mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
        mx_printstrlen(str, len, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);  
        if (i + 1 < dir->array.size) {
            print_spaces(mx_get_data_len(info, dir, dt, true),
                        mx_get_data_len(info, dir, dt, false), &dir->off);
        }
    }
    mx_printchar('\n', 1);
}
