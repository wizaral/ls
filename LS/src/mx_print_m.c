#include "uls.h"



// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_print_m(t_dir *dir) {
    t_file **dt = NULL;

    dir->off.curpos = 0;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        dir->info->print.inode(dir, i);
        dir->off.curpos += mx_strlen((*dt)->fields.name) + 2;
        if (dir->off.curpos < dir->off.term_width) {
            mx_printstr((*dt)->fields.name, 1);
            mx_printstr(", ", 1);
        }
        else {
            mx_printstr("\n", 1);
            mx_printstr((*dt)->fields.name, 1);
            mx_printstr(", ", 1);
            dir->off.curpos = 0;
        }
    }
}
