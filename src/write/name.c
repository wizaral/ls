#include "uls.h"

static inline void file(char *access) {
    if (access[3] == 's') {
        mx_printstrlen(MX_UIB, 8, 1);
    }
    else if (access[6] == 's') {
        mx_printstrlen(MX_GIB, 8, 1);
    }
    else if (access[3] == 'x' || access[6] == 'x'
        || access[9] == 'x' || access[9] == 't') {
        mx_printstrlen(MX_EXE, 7, 1);
    }
}

static inline void dir(char *access) {
    if (access[8] == 'w') {
        if (access[9] == 'T' || access[9] == 't') {
            mx_printstrlen(MX_SKB, 8, 1);
        }
        else {
            mx_printstrlen(MX_NSB, 8, 1);
        }
    }
    else {
        mx_printstrlen(MX_DIR, 7, 1);
    }
}

static inline void set_color(char *access) {
    if (access[0] == '-')
        file(access);
    else if (access[0] == 'd')
        dir(access);
    else if (access[0] == 's')
        mx_printstrlen(MX_SCK, 7, 1);
    else if (access[0] == 'p')
        mx_printstrlen(MX_FIF, 7, 1);
    else if (access[0] == 'l')
        mx_printstrlen(MX_LNK, 7, 1);
    else if (access[0] == 'b')
        mx_printstrlen(MX_BLK, 8, 1);
    else if (access[0] == 'c')
        mx_printstrlen(MX_CHR, 8, 1);
}

void mx_color(t_file *file) {
    set_color(file->fields.access);
    mx_printstrlen(file->fields.name, file->lengths.name, 1);
    mx_printstrlen(MX_DEF, 4, 1);
}

void mx_nocolor(t_file *file) {
    mx_printstrlen(file->fields.name, file->lengths.name, 1);
}
