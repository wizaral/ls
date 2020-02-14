#include <uls.h>


// Флаг 1, по сути тупо добавить ф-ции модификаторов тут даже считать ничё не надо
void mx_print_1(t_info *info) {
    for (size_t i = 0; i < info->array.size; ++i) {
        t_file **dt = mx_at(&info->array, i);
        
        info->print.inode(info);
        printf("%s\n", (*dt)->name);
    }
}
