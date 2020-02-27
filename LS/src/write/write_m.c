#include "uls.h"

static void write_data(t_dir *dir, t_file *file, int len, bool newline) {        // дабы по сути не дублировать код бахнул просто флаг
    mx_printstrlen("\n", newline, 1);
    newline ? (dir->off.x = len) : 0;
    mx_printstrlen(file->fields.inode, file->lengths.inode, 1);
    mx_printstrlen(file->fields.bsize, file->lengths.bsize, 1);
    dir->info->print_name(file);
    mx_printchar(file->fields.suffix, 1);  
    mx_printstrlen(", ", 2, 1);
}

// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_write_m(t_dir *dir) {
    t_file *dt = NULL;
    int len = dir->off.x = 0;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);

        dir->off.x += (len = dt->lengths.name + dt->lengths.inode
        + dt->lengths.bsize + (dir->info->get.suffix != zaglushka) + 2);
        write_data(dir, dt, len, dir->off.width < dir->off.x);                             // Выводит данные файла с новой строки или нет (не с новой)
    }
}
