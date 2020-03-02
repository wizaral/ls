#include "uls.h"

void mx_user_id(t_dir *dir, t_file *file, t_stat *st) {
    struct passwd *pw = getpwuid(st->st_uid);
    size_t len = mx_get_num_length(pw->pw_uid, 10);

    file->uid = pw->pw_uid;
    file->fields.user = mx_itoa(pw->pw_uid);
    file->lengths.user = len;
    dir->off.uid = len;
}

void mx_user(t_dir *dir, t_file *file, t_stat *st) {
    struct passwd *pw = getpwuid(st->st_uid);
    size_t len = mx_strlen(pw->pw_name);

    file->uid = pw->pw_uid;
    file->fields.user = pw->pw_name;
    file->lengths.user = len;
    dir->off.uid = len;
}

void mx_user_nothing(t_dir *dir, t_file *file, t_stat *st) {
    ++dir;
    ++file;
    ++st;
}
