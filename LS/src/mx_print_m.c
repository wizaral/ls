#include <uls.h>


// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_print_m(t_info *info) {
    for (size_t i = 0; i < info->array.size; ++i) {
        t_file **dt = mx_at(&info->array, i);
        
        info->print.inode(info);
        printf("%s, ", (*dt)->name);

    }
}
