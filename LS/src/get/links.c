#include "uls.h"

void mx_links(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    char *lnum = mx_itoa(st->st_nlink);
    int len = mx_strlen(lnum);

    file->links = st->st_nlink;
    file->fields.links = lnum;
    file->lengths.links = len;
    dir->off.links = len;
    ++info;
}
