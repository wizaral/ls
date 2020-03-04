#include "uls.h"

void mx_suffix(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISDIR(st->st_mode))
        file->fields.suffix = '/';
    else if (st->st_mode & S_IXUSR)
        file->fields.suffix = '*';
    else if (MX_ISLNK(st->st_mode))
        file->fields.suffix = '@';
    else if (MX_ISSOCK(st->st_mode))
        file->fields.suffix = '=';
    else if (MX_ISWHT(st->st_mode))
        file->fields.suffix = '%';
    else if (MX_ISFIFO(st->st_mode))
        file->fields.suffix = '|';
    else
        file->fields.suffix = ' ';
    ++dir;
}
