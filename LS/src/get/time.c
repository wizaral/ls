#include "uls.h"

void mx_get_time(t_dir *d, t_file *f, struct stat *s) { // пока там ебанул мб ты выдумаешь как просто
    t_time_type type = d->info->time_type;              // прибавить например

    if (type = last_access)
        f->time = s->st_atimespec;
    else if (type = modification)
        f->time = s->st_mtimespec;
    else if (type = change)
        f->time = s->st_ctimespec;
    else if (type = creation)
        f->time = s->st_birthtimespec;
}
