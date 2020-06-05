#include "uls.h"

static inline void get_name(t_dir *dir, t_dirent *dirent, t_file *file) {
    file->fields.name = mx_memdup(dirent->d_name, dirent->d_namlen + 1);
    file->lengths.name = dirent->d_namlen;

    if (dir->off.name < file->lengths.name) {
        dir->off.name = file->lengths.name;
    }
}

void mx_not_printable(t_dir *dir, t_file *file, t_stat *st) {
    get_name(dir, dir->file, file);
    (void)st;
}

void mx_only_printable(t_dir *dir, t_file *file, t_stat *st) {
    get_name(dir, dir->file, file);
    (void)st;

    for (int i = file->lengths.name - 1; i > -1; --i) {
        if (!mx_isprint(file->fields.name[i])) {
            file->fields.name[i] = '?';
        }
    }
}
