#include "uls.h"

void mx_time(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    file->time = *(&st->st_atimespec + info->time_type);
    // time to str
    ++dir;
}
