#include "uls.h"

static void write_data(t_dir *dir, t_file *file, int len, t_info *info) {        // дабы по сути не дублировать код бахнул просто флаг
    mx_printstrlen("\n", dir->off.x < dir->off.width, 1);
    dir->off.x < dir->off.width ? (dir->off.x = len) : 0;
    mx_printstrlen(file->fields.inode, file->lengths.inode, 1);
    mx_printstrlen(file->fields.bsize, file->lengths.bsize, 1);
    info->print_name(file);
    mx_printstrlen(&file->fields.suffix, file->lengths.suffix, 1);
    mx_printstrlen(", ", 2, 1);
}

// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_write_m(t_info *info, t_dir *dir) {
    t_file *dt = NULL;
    int len = dir->off.x = 0;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);

        dir->off.x += (len = dt->lengths.name + dt->lengths.inode + (dt->lengths.inode != 0)
        + dt->lengths.bsize + (dt->lengths.bsize != 0) + (info->get.suffix != mx_dummy) + 2);
        if (i + 1 == dir->array.size) {
            mx_printstrlen("\n", dir->off.x < dir->off.width, 1);
            dir->off.x < dir->off.width ? (dir->off.x = len) : 0;
            mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
            mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
            info->print_name(dt);
            mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
            mx_printstrlen("\n", 1, 1);
        }
        else 
            write_data(dir, dt, len, info);                             // Выводит данные файла с новой строки или нет (не с новой)
    }
    ++info;
    ++dir;
}
