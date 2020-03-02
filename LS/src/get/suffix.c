#include "uls.h"

void mx_get_suffix(t_dir *d, t_file *f, t_stat *s) {
    if (MX_ISDIR(s->st_mode))
        f->fields.suffix = '/';
    else if (s->st_mode & S_IXUSR)
        f->fields.suffix = '*';
    else if (MX_ISLNK(s->st_mode))
        f->fields.suffix = '@';
    else if (MX_ISSOCK(s->st_mode))
        f->fields.suffix = '=';
    else if (MX_ISWHT(s->st_mode))
        f->fields.suffix = '%';
    else if (MX_ISFIFO(s->st_mode))
        f->fields.suffix = '|';
    ++d;
}
