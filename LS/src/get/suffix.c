#include "uls.h"

void mx_suffix_all(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISDIR(st->st_mode))
        file->fields.suffix = '/';
    else if (MX_ISLNK(st->st_mode))
        file->fields.suffix = '@';
    else if (MX_ISSOCK(st->st_mode))
        file->fields.suffix = '=';
    else if (MX_ISWHT(st->st_mode))
        file->fields.suffix = '%';
    else if (MX_ISFIFO(st->st_mode))
        file->fields.suffix = '|';
    else if (st->st_mode & S_IXUSR)
        file->fields.suffix = '*';
    else
        file->fields.suffix = '\0';
    ++info;
    ++dir;

    file->lengths.suffix = file->fields.suffix ? 1 : 0;
}

void mx_suffix_dir(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    file->fields.suffix = MX_ISDIR(st->st_mode) ? '/' : '\0';
    file->lengths.suffix = file->fields.suffix ? 1 : 0;
    ++info;
    ++dir;
}
