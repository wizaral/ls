#include "uls.h"

void mx_get_group_id(t_dir *dir, t_file *file, struct stat *st) {
    struct group *gid = getgrgid(st->st_gid);
    int len = mx_get_num_length(gid->gr_gid, 10);

    file->gid = gid->gr_gid;
    file->fields.grp = mx_itoa(gid->gr_gid);
    file->lengths.grp = len;
    dir->off.gid = len;
}


void mx_get_group_name(t_dir *dir, t_file *file, struct stat *st) {
    struct group *gid = getgrgid(st->st_gid);
    int len = mx_strlen(gid->gr_name);

    file->gid = gid->gr_gid;
    file->fields.grp = gid->gr_name;
    file->lengths.grp = len;
    dir->off.gid = len;
}

void mx_get_group_nothing(t_dir *dir, t_file *file, struct stat *st) {
    ++dir;
    ++file;
    ++st;
}
