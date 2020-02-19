#include "uls.h"



// Тут несложно посчитаю как выводить когда будет структура offsets
void mx_print_m(t_info *info) {
    t_file **dt = NULL;
    t_offset off;

    off.curpos = 0;

    for (size_t i = 0; i < vector.size; ++i) {
        dt = mx_at(vector, i);
        info->print.inode(info);
        off.curpos += mx_strlen((*dt)->fields.name) + 2;
        if (off.curpos < off.term_width) {
            mx_printstr((*dt)->fields.name, 1);
            mx_printstr(", ", 1);
        }
        else {
            mx_printstr("\n", 1);
            mx_printstr((*dt)->fields.name, 1);
            mx_printstr(", ", 1);
            off.curpos = 0;
        }
    }
}
