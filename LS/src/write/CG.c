#include "uls.h"

// static int get_longest_size(t_offset *off, t_info *info) {
//     return off->filename + off->inode + off->bsize
//            + (info->get.suffix != mx_dummy);
// }

// static int get_file_size(t_file *file, t_info *info) {
//     return file->lengths.name + file->lengths.inode
//            + file->lengths.bsize + (info->get.suffix != mx_dummy);
// }

// static int get_colnum(t_offset off, t_info *info) {                                           // get number of cols i -C out
//     return off.width / get_longest_size(&off, info);
// }

// static int get_row(size_t vsize, t_offset off) {                                // get number of rows i -C out
//     // return (vsize % off.columns) ? vsize / off.columns + 1 : vsize / off.columns;
//     return (vsize / off.columns) + ((vsize % off.columns) != 0);
// }

// static void init_data(t_info *info, t_dir *dir) {
//     dir->off.columns = get_colnum(dir->off, info);
//     dir->off.rows = get_row(dir->array.size, dir->off);
// }

// static void print_n_spaces(t_info *info, t_dir *dir, t_file *file) {
//     int longest_len = get_longest_size(&dir->off, info);
//     int current_len = get_file_size(file, info);

//     for (int i = 0; i < longest_len - current_len + 1; ++i)                   // print tabs depending on numb of tabs in lword and cword;
//         mx_printstrlen(" ", 1, 1);
// }

void mx_write_CG(t_info *info, t_dir *dir) {
    // t_file *dt = NULL;

    // init_data(info, dir);
    // for (size_t i = 0; i < (size_t)dir->off.rows; ++i) {
    //     for (size_t j = i; j < dir->array.size; j += dir->off.rows) {
    //         dt = mx_at(&dir->array, j);
    //         if (j < dir->array.size) {
    //             mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);         // print inode
    //             mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);         // print bsize
    //             info->print_name(dt);                                           // print name
    //             mx_printchar(dt->fields.suffix, 1);                             // print suffix
    //             if (j + dir->off.rows != dir->array.size)
    //                 print_n_spaces(info, dir, dt);
    //         }
    //     }
    //     mx_printstr("\n", 1);
    // }
    ++info;
    ++dir;
}
