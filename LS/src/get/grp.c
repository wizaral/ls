#include "uls.h"

void mx_group_id(t_dir *dir, t_file *file, t_stat *st) {
    struct group *gid = getgrgid(st->st_gid);
    int len = mx_get_num_length(gid->gr_gid, 10);

    file->gid = gid->gr_gid;
    file->fields.grp = mx_itoa(gid->gr_gid);
    file->lengths.grp = len;
    dir->off.gid = len;
}

void mx_group(t_dir *dir, t_file *file, t_stat *st) {
    struct group *gid = getgrgid(st->st_gid);
    int len = mx_strlen(gid->gr_name);

    file->gid = gid->gr_gid;
    file->fields.grp = gid->gr_name;
    file->lengths.grp = len;
    dir->off.gid = len;
}
