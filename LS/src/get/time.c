#include "uls.h"

void mx_time_full(t_dir *dir, t_file *file, t_stat *st) {
    char *temp = ctime(&file->time.tv_sec) + 4;

    file->fields.time = mx_memdup(temp, 20);
    file->lengths.time = 20;
    ++dir;
    ++st;
}

void mx_time_short(t_dir *dir, t_file *file, t_stat *st) {
    char *temp = ctime(&file->time.tv_sec) + 4;
    time_t now = time(NULL);

    if ((now - file->time.tv_sec) < MX_HALF_YEAR || file->time.tv_sec > now)
        file->fields.time = mx_memdup(temp, 12);
    else {
        file->fields.time = malloc(12);
        mx_memcpy(file->fields.time, temp, 7);
        mx_memcpy(file->fields.time + 7, temp + 15, 5);
    }
    file->lengths.time = 12;
    ++dir;
    ++st;
}
