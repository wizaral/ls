#include "uls.h"

// Флаг 1, по сути тупо добавить ф-ции модификаторов тут даже считать ничё не надо
void mx_write_1(t_dir *dir) {
    t_file *dt = NULL;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
        mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
        dir->info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, info->get.suffix != zaglushka, 1);
        mx_printchar('\n', 1);
    }
}
