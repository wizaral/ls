#include "uls.h"

static int get_data_len(t_info *info, t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.name + dir->off.inode + (dir->off.inode != 0)
             + dir->off.bsize + (info->get.suffix != mx_dummy);

    return file->lengths.name
         + file->lengths.inode + (file->lengths.inode != 0)
         + file->lengths.bsize + (file->lengths.bsize != 0)
         + file->lengths.suffix;
}

static int get_tabs(int size) {
    int count = 0;

    for (; size >= 8; size -= 8)
        ++count;
    return count;
}

static void print_n_tabs(uint8_t ltabs, uint8_t ctabs) {
    uint8_t tabs = ltabs - ctabs;

    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen("\t", 1, 1);
}

static void init_data(t_info *info, t_dir *dir) {
    int len = get_data_len(info, dir, NULL, true);

    dir->off.width = mx_winsize(info);
    dir->off.columns = dir->off.width / (len + (8 - len % 8));
    dir->off.rows = (dir->array.size / dir->off.columns)
                    + ((dir->array.size % dir->off.columns) != 0);
    dir->off.name_tabs = get_tabs(len) + 1;
}

void mx_write_C(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    uint8_t tabs_in_cword = 0;

    init_data(info, dir);                                                       // init data needed for output
    for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {                        // walk through every row
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {           // walk of all elements of i row
            dt = mx_at(&dir->array, j);                                         // take data from vector
            if (j < dir->array.size) {                                          // check if we are out of vector or not
                tabs_in_cword = get_tabs(get_data_len(info, dir, dt, false));   // get tabs in cword (current word)
                mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);         // print inode
                mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);         // print bsize
                info->print_name(dt);                                           // print name
                mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);                             // print suffix
                if (j + dir->off.rows <= dir->array.size)                      // check if this is last file in row so we dont print tabs 
                    print_n_tabs(dir->off.name_tabs, tabs_in_cword);
            }
        }
        mx_printstrlen("\n", 1, 1);                                             // go to new row;
    }
}
