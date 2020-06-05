#include "uls.h"

void mx_grp_id(t_dir *dir, t_file *file, t_stat *st) {
    file->lengths.grp = mx_unumlen(st->st_gid, 10);
    file->fields.grp = mx_ulltoa(st->st_gid);

    if (dir->off.grp < file->lengths.grp) {
        dir->off.grp = file->lengths.grp;
    }
}

void mx_grp_name(t_dir *dir, t_file *file, t_stat *st) {
    struct group *grp = getgrgid(st->st_gid);

    if (grp) {
        file->lengths.grp = mx_strlen(grp->gr_name);
        file->fields.grp = mx_memdup(grp->gr_name, file->lengths.grp);
    }
    else {
        file->lengths.grp = mx_unumlen(st->st_gid, 10);
        file->fields.grp = mx_ulltoa(st->st_gid);
    }
    if (dir->off.grp < file->lengths.grp) {
        dir->off.grp = file->lengths.grp;
    }
}

void mx_grp_skip(t_dir *dir, t_file *file, t_stat *st) {
    (void)dir;
    (void)file;
    (void)st;
}
