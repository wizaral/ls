#include "uls.h"

void mx_get_time(t_dir *d, t_file *f, struct stat *s) { // пока там ебанул мб ты выдумаешь как просто
    f->time = *(&s->st_atimespec + d->info->time_type);
}
