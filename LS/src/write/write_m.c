#include "uls.h"

// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_write_m(t_dir *dir) {
    t_file **dt = NULL;

    dir->off.curpos_in_term = 0;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        dir->info->print.inode(dir, i);
        dir->off.curpos_in_term += mx_strlen((*dt)->drnt->d_name) + 2 + (*dt)->fields.lengths.inode;
        if (dir->off.curpos_in_term < dir->off.term_width) {
            mx_printstr((*dt)->drnt->d_name, 1);
            mx_printstr(", ", 1);
        }
        else {
            mx_printstr("\n", 1);
            mx_printstr((*dt)->drnt->d_name, 1);
            mx_printstr(", ", 1);
            dir->off.curpos_in_term = mx_strlen((*dt)->drnt->d_name) + 2;
        }
    }
}
