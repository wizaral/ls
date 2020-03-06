#include "uls.h"

static void calc_x(t_info *info, t_file *dt, int *len, t_dir *dir) {
    dir->off.x += (*len = dt->lengths.name + mx_get_inode_bsize_len(&dir->off)
                + (info->get.suffix != mx_dummy) + 2);
    if (dir->off.x - mx_get_inode_bsize_len(&dir->off) > dir->off.width) {
        mx_printstrlen("\n", 1, 1);
        dir->off.x = *len + 1;
    }
}

void mx_write_m(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    int len = dir->off.x = 0;
    size_t len_addition = mx_get_inode_bsize_len(&dir->off);
    char str[len_addition];

    dir->off.width = mx_winsize(info);
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        calc_x(info, dt, &len, dir);
        mx_memset(str, ' ', len_addition);
        mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
        mx_printstrlen(str, len_addition, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
        if (i + 1 != dir->array.size)
            mx_printstrlen(", ", 2, 1);
        else
            mx_printstrlen("\n", 1, 1);
    }
}
