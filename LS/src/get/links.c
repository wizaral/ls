#include "uls.h"

void mx_get_lnum(t_dir *dir, t_file *file, struct stat *st) {
    char *lnum = mx_itoa(st->st_nlink);
    int len = mx_strlen(lnum);

    file->links = st->st_nlink;
    file->fields.links = lnum;
    file->lengths.links = len;
    dir->off.links = len;
}
