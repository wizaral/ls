#include "uls.h"

static void print_n_spaces(uint8_t ltabs, uint8_t ctabs, t_info *info) {
    uint8_t tabs = ltabs - ctabs;
    info++;

    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen(" ", 1, 1);
}

static void init_data(t_info *info, t_dir *dir) {
    int len = mx_get_data_len(info, dir, NULL, true);

    dir->off.width = mx_winsize(info);
    dir->off.columns = dir->off.width / (len + 1);
    dir->off.rows = (dir->array.size / dir->off.columns)
                  + ((dir->array.size % dir->off.columns) != 0);
    dir->off.name_tabs = len + 1;
}

static void print_name_and_suffix(t_info *info, t_file *dt) {
    info->print_name(dt);                                           // print name
    mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);      // print suffix
}

void mx_write_CG(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    size_t len = mx_get_inode_bsize_len(&dir->off);
    char str[len];

    init_data(info, dir);                                                       // init data needed for output
    for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {                        // walk through every row
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {           // walk of all elements of i row
            dt = mx_at(&dir->array, j);                                         // take data from vector
            if (j < dir->array.size) {                                          // check if we are out of vector or not
                mx_memset(str, ' ', len);
                mx_make_inode_bsize(&dir->off, str, &dt->fields, &dt->lengths);
                mx_printstrlen(str, len, 1);
                print_name_and_suffix(info, dt);
                if (j + dir->off.rows < dir->array.size)                       // check if this is last file in row so we dont print tabs 
                    print_n_spaces(dir->off.name_tabs,
                                   mx_get_data_len(info, dir, dt, false), info);
            }
        }
        mx_printstrlen("\n", 1, 1);                                             // go to new row;
    }
}
