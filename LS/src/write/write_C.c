#include "uls.h"

static int get_longest_size(t_offset *off, t_info *info) {
    return off->file_name + off->inode + off->bsize
        + (info->get.suffix != zaglushka);
}
static int get_file_size(t_file *file, t_info *info) {
    return file->lengths.name + file->lengths.inode
        + file->lengths.bsize + (info->get.suffix != zaglushka);
}

static int get_tabsin_file(t_file *file, t_info *info) {
    int count = 0;
    int file_tabs = get_file_size(file, info);

    for (; file_tabs >= 8; file_tabs -= 8)
        ++count;
    return count;
}

static int get_colnum(t_offset off, t_info *info) {                                           // get number of cols i -C out
    int lognest_size = get_longest_size(&off, info);

    return off.width / (lognest_size  + (8 - lognest_size % 8));
}

static int get_row(size_t vsize, t_offset off) {                                // get number of rows i -C out
    // return (vsize % off.columns) ? vsize / off.columns + 1 : vsize / off.columns;
    return (vsize / off.columns) + ((vsize % off.columns) != 0);
}

static void init_data(t_dir *dir) {
    dir->off.columns = get_colnum(dir->off, dir->info);
    dir->off.rows = get_row(dir->array.size, dir->off);
}

static void print_n_tabs(uint8_t ltabs, uint8_t ctabs) {
    uint8_t tabs = ltabs - ctabs ? ltabs - ctabs : 1;

    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen("\t", 1, 1);
}

void mx_write_c(t_dir *dir) {
    t_file *dt = NULL;
    uint8_t tabs_in_cword = 0;

    init_data(dir);                                                               // init data needed for output
    for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {                          // walk through every row
        for (size_t j = i; j < dir->array.size; j += dir->off.rows) {             // walk of all elements of i row
            dt = mx_at(&dir->array, j);                                           // take data from vector
            if (j < dir->array.size) {                                            // check if we are out of vector or not
                tabs_in_cword = get_tabsin_file(dt, dir->info);                   // get tabs in cword (current word)
                mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);           // print inode
                mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);           // print bsize
                dir->info->print_name(dt);                                        // print name
                mx_printchar(dt->fields.suffix, 1);                               // print suffix
                if (j + dir->off.rows != dir->array.size)                         // check if this is last file in row so we dont print tabs
                    print_n_tabs(dir->off.file_name_tabs, tabs_in_cword);
            }
        }
        mx_printstrlen("\n", 1, 1);                                               // go to new row;
    }
}
