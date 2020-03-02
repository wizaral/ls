#include "uls.h"

void mx_get_group(t_dir *dir, t_file *file, struct stat *st) {
    struct passwd *gid = getpwuid(st->st_uid);

    // for numericaly represented user
    file->uid = gid->pw_uid;
    file->fields.user = mx_itoa(gid->pw_uid);
    file->lengths.user = mx_get_num_length(gid->pw_uid, 10);
    // for name of a user
    file->gid = gid->pw_uid;
    file->fields.user = mx_itoa(gid->pw_name);
    file->lengths.user = mx_strlen(gid->pw_name);
}
