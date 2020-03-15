#include "uls.h"

static void print_n_tabs(uint8_t ltabs, uint8_t ctabs) {
    uint8_t tabs = ltabs - ctabs;

    for (int i = 0; i < tabs; ++i)
        mx_printchar('\t', 1);
}

static void init_data(t_info *info, t_dir *dir) {
    int len = mx_get_data_len(info, dir, NULL, true);

    dir->off.width = mx_winsize(info);
    dir->off.columns = dir->off.width /
                       ((len + (8 - len % 8)) ? (len + (8 - len % 8)) : 1);
    dir->off.rows = (dir->array.size /
                    (dir->off.columns ? dir->off.columns : 1))
                  + ((dir->array.size
                  % (dir->off.columns ? dir->off.columns : 1)) != 0);
    dir->off.name_tabs = mx_get_tabs(len) + 1;
}

static void print(t_info *info, t_dir *dir, t_file *file, size_t j) {
    uint8_t tabs_in_cword = 0;

    if (j < dir->array.size) {
        tabs_in_cword = mx_get_tabs(mx_get_data_len(info, dir, file, false));
        info->print_name(file);
        mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
        if (j + dir->off.rows < dir->array.size)
            print_n_tabs(dir->off.name_tabs, tabs_in_cword);
    }
}

void mx_write_C(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];

    init_data(info, dir);
    for (size_t i = 0; i < dir->off.rows; ++i) {
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {
            dt = mx_at(&dir->array, j);
            mx_memset(str, ' ', len);
            mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
            mx_printstrlen(str, len, 1);
            print(info, dir, dt, j);
        }
        mx_printchar('\n', 1);
    }
}
