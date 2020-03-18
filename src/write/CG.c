#include "uls.h"

static inline void print_n_spaces(uint8_t ltabs, uint8_t ctabs) {
    uint8_t tabs = ltabs - ctabs;

    for (int i = 0; i < tabs; ++i)
        mx_printchar(' ', 1);
}

static void init_data(t_info *info, t_dir *dir) {
    int len = mx_get_data_len(info, dir, NULL, true);

    dir->off.width = mx_winsize(info);
    dir->off.columns = dir->off.width / (len + 1);
    dir->off.rows = (dir->array.size / dir->off.columns)
                    + ((dir->array.size % dir->off.columns) != 0);
    dir->off.name_tabs = len + 1;
}

void mx_write_CG(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];

    init_data(info, dir);
    for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {
            dt = mx_at(&dir->array, j);
            mx_memset(str, ' ', len);
            mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
            mx_printstrlen(str, len, 1);
            info->print_name(dt);
            mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
            if (j + dir->off.rows < dir->array.size)
                print_n_spaces(dir->off.name_tabs,
                                mx_get_data_len(info, dir, dt, 0));
        }
        mx_printchar('\n', 1);
    }
}
