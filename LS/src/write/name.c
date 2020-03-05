#include "uls.h"

void mx_nocolor(t_file *file) {
    mx_printstrlen(file->fields.name, file->lengths.name, 1);
}

void mx_color(t_file *file) {
    mx_printstrlen(file->fields.name, file->lengths.name, 1);
    ++file;
}
