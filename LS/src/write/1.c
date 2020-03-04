#include "uls.h"

void print(t_info *info, t_file *file) {
    t_file *pfile = file;

    mx_printstrlen(pfile->fields.inode, pfile->lengths.inode, 1);
    mx_printstrlen(pfile->fields.bsize, pfile->lengths.bsize, 1);
    info->print_name(pfile);
    mx_printstrlen(&pfile->fields.suffix, pfile->lengths.suffix, 1);
    mx_printchar('\n', 1);
}

void mx_write_1(t_info *info, t_dir *dir) {
    info->foreach(info, (t_file *)dir->array.arr, dir->array.size, print);
}
