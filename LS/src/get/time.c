#include "uls.h"

void mx_time_full(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    // file->time = *(&st->st_atimespec + info->time_type); // это должно быть не тут
    // time to str
    ++info;
    ++dir;
    ++file;
    ++st;
}

void mx_time_short(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    ++info;
    ++dir;
    ++file;
    ++st;
}
