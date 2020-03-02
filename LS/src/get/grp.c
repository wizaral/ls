#include "uls.h"

void mx_get_group(t_dir *dir, t_file *file, struct stat *st) {
    struct group *gid = getgrgid(st->st_gid);

    // for numericaly represented group
    file->gid = gid->gr_gid;
    file->fields.grp = mx_itoa(gid->gr_gid);
    file->lengths.grp = mx_get_num_length(gid->gr_gid, 10);
    // for name of a group
    file->gid = gid->gr_gid;
    file->fields.grp = gid->gr_name;
    file->lengths.grp = mx_strlen(gid->gr_name);
}
