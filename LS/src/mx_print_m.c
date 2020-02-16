#include "uls.h"

// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_print_m(t_info *info) {
    t_file **dt = NULL;

    for (size_t i = 0; i < info->array.size; ++i) {
        dt = mx_at(&info->array, i);
        info->print.inode(info);
        mx_printstr((*dt)->name, 1);
        mx_printstr(", ", 1);
    }
}
