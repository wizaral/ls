#include "uls.h"

static inline void get_name(t_dirent *dirent, t_file *file) {
    file->lengths.name = dirent->d_namlen;
    file->fields.name = mx_strndup(dirent->d_name, dirent->d_namlen);
}

void mx_not_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    get_name(dir->file, file);
    if (dir->off.name < file->lengths.name)
        dir->off.name = file->lengths.name;
    ++info;
    ++st;
}

void mx_only_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    get_name(dir->file, file);
    if (dir->off.name < file->lengths.name)
        dir->off.name = file->lengths.name;
    for (int i = file->lengths.name - 1; i > -1; --i)
        if (!mx_isprint(file->fields.name[i]))
            file->fields.name[i] = '?';
    ++info;
    ++st;
}
