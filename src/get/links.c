#include "uls.h"

void mx_links(t_dir *dir, t_file *file, t_stat *st) {
    int link_len = mx_numlen(st->st_nlink, 10);

    file->fields.links = mx_lltoa(st->st_nlink);
    file->lengths.links = link_len;

    if (dir->off.links < link_len) {
        dir->off.links = link_len;
    }
}
