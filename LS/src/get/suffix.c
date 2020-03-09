#include "uls.h"

void mx_suffix_all(t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISDIR(st->st_mode))
        file->fields.suffix = '/';
    else if (MX_ISLNK(st->st_mode))
        file->fields.suffix = '@';
    else if (MX_ISSCK(st->st_mode))
        file->fields.suffix = '=';
    else if (MX_ISWHT(st->st_mode))
        file->fields.suffix = '%';
    else if (MX_ISFIF(st->st_mode))
        file->fields.suffix = '|';
    else if (st->st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
        file->fields.suffix = '*';
    else
        file->fields.suffix = '\0';

    file->lengths.suffix = file->fields.suffix != 0;
    if (dir->off.name < file->lengths.name + file->lengths.suffix)
        dir->off.name = file->lengths.name + file->lengths.suffix;
}

void mx_suffix_dir(t_dir *dir, t_file *file, t_stat *st) {
    file->fields.suffix = MX_ISDIR(st->st_mode) ? '/' : '\0';
    file->lengths.suffix = file->fields.suffix != 0;
    if (dir->off.name < file->lengths.name + file->lengths.suffix)
        dir->off.name = file->lengths.name + file->lengths.suffix;
}
