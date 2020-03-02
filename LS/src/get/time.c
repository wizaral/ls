#include "uls.h"

void mx_get_time(t_dir *d, t_file *f, struct stat *s) {
    f->time = *(&s->st_atimespec + d->info->time_type);
}
