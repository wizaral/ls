#include "uls.h"

static void write_data(t_dir *dir, t_file *file, int len, bool newline) {        // дабы по сути не дублировать код бахнул просто флаг
    if (newline) {
        mx_printstr("\n", 1);
        dir->off.x = len;
    }
    mx_printstrlen(file->fields.inode, file->lengths.inode, 1);
    mx_printstrlen(file->fields.bsize, file->lengths.bsize, 1);
    dir->info->print_name(file);
    mx_printchar(file->fields.suffix, 1);  
    mx_printstrlen(", ", 2, 1);
}

// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_write_m(t_dir *dir) {
    t_file *dt = NULL;
    int len = 0;

    dir->off.x = 0;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        
        len = dt->lengths.name + dt->lengths.inode
            + dt->lengths.bsize
            + (dir->info->get.suffix != zaglushka) + 2;
        dir->off.x += len;
        if (dir->off.x < dir->off.width)
            write_data(dir, dt, len, false);                             // Выводит данные файла с новой строки или нет (не с новой)
        else
            write_data(dir, dt, len, true);                              // Выводит данные файла с новой строки или нет (с новой)
    }
}
