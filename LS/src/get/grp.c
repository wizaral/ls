#include "uls.h"

void mx_group(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    struct group *grp = getgrgid(st->st_gid);

    if (grp) {
        file->lengths.grp = mx_strlen(grp->gr_name);
        file->fields.grp = mx_memdup(grp->gr_name, file->lengths.grp);
    }
    else {
        file->lengths.grp = mx_unumlen(st->st_gid, 10);
        file->fields.grp = mx_lltoa(st->st_gid);
    }
    if (dir->off.grp < file->lengths.grp)
        dir->off.grp = file->lengths.grp;
    ++info;
}
