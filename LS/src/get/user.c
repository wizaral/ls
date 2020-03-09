#include "uls.h"

void mx_user_id(t_dir *dir, t_file *file, t_stat *st) {
    file->lengths.user = mx_unumlen(st->st_uid, 10);
    file->fields.user = mx_lltoa(st->st_uid);
    if (dir->off.user < file->lengths.user)
        dir->off.user = file->lengths.user;
}

void mx_user_name(t_dir *dir, t_file *file, t_stat *st) {
    struct passwd *pw = getpwuid(st->st_uid);

    if (pw) {
        file->lengths.user = mx_strlen(pw->pw_name);
        file->fields.user = mx_memdup(pw->pw_name, file->lengths.user);
    }
    else {
        file->lengths.user = mx_unumlen(st->st_uid, 10);
        file->fields.user = mx_lltoa(st->st_uid);
    }
    if (dir->off.user < file->lengths.user)
        dir->off.user = file->lengths.user;
}

void mx_user_skip(t_dir *dir, t_file *file, t_stat *st) {
    ++dir;
    ++file;
    ++st;
}
