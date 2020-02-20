#include "uls.h"

// Флаг 1, по сути тупо добавить ф-ции модификаторов тут даже считать ничё не надо
void mx_print_1(t_dir *dir) {
    t_file **dt = NULL;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        dir->info->print.inode(dir, i);
        mx_printstr((*dt)->fields.name, 1);
    }
}
