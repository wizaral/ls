#include "uls.h"

static inline void print_n_tabs(int tabs) {
    for (int i = 0; i < tabs; ++i)
        mx_printchar('\t', 1);
}

static void print_tabs(t_info *info, t_dir *dir, t_file *dt) {
    int full_len_longest = mx_get_data_len(info, dir, dt, true);
    int full_len_current = mx_get_data_len(info, dir, dt, false);
    uint8_t tabs_cword = mx_get_tabs(mx_get_data_len(info, dir, dt, false));

    if (dir->off.width >= dir->off.x + dir->off.name_tabs * 16) {
        dir->off.x += dir->off.name_tabs * 8;
        print_n_tabs(full_len_longest - full_len_current ?
                    dir->off.name_tabs - tabs_cword : 1);
    }
    else {
        mx_printchar('\n', 1);
        dir->off.x = 0;
    }
}

void mx_write_x(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];

    dir->off.width = mx_winsize(info);
    dir->off.x = 0;
    dir->off.name_tabs = mx_get_tabs(mx_get_data_len(info, dir, NULL, 1)) + 1;
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_memset(str, ' ', len);
        mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
        mx_printstrlen(str, len, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
        if (i + 1 < dir->array.size)
            print_tabs(info, dir, dt);
    }
    mx_printchar('\n', 1);
}
