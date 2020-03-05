#include "uls.h"

static int get_data_len(t_info *info, t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.name + dir->off.inode + (dir->off.inode != 0)
             + dir->off.bsize + (dir->off.bsize != 0)
             + (info->get.suffix != mx_dummy);

    return file->lengths.name + file->lengths.inode
         + (file->lengths.inode != 0)
         + file->lengths.bsize + (file->lengths.bsize != 0)
         + file->lengths.suffix;
}

static void print_n_spaces(uint8_t ltabs, uint8_t ctabs, t_info *info) {
    uint8_t tabs = ltabs - ctabs;
    info++;

    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen(" ", 1, 1);
}

static void print_inode(t_dir *dir, t_file *file) {
    for (int i = 0; i < dir->off.inode - file->lengths.inode; ++i)
        mx_printstrlen(" ", 1, 1);
    mx_printstrlen(file->fields.inode, file->lengths.inode, 1);
    if (file->lengths.inode)
        mx_printstrlen(" ", 1, 1);
}

static void init_data(t_info *info, t_dir *dir) {
    int len = get_data_len(info, dir, NULL, true);

    dir->off.width = mx_winsize(info);
    dir->off.columns = dir->off.width / len;
    dir->off.rows = (dir->array.size / dir->off.columns)
                    + ((dir->array.size % dir->off.columns) != 0);
    dir->off.name_tabs = len + 1;
}

void mx_write_CG(t_info *info, t_dir *dir) {
    t_file *dt = NULL;

    init_data(info, dir);                                                       // init data needed for output
    for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {                        // walk through every row
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {           // walk of all elements of i row
            dt = mx_at(&dir->array, j);                                         // take data from vector
            if (j < dir->array.size) {                                          // check if we are out of vector or not
                print_inode(dir, dt);                                           // print inode
                mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);         // print bsize
                info->print_name(dt);                                           // print name
                mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);      // print suffix
                if (j + dir->off.rows < dir->array.size)                       // check if this is last file in row so we dont print tabs 
                    print_n_spaces(dir->off.name_tabs,
                                   get_data_len(info, dir, dt, false), info);
            }
        }
        mx_printstrlen("\n", 1, 1);                                             // go to new row;
    }
}
