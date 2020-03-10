#include "uls.h"

void mx_attr(t_dir *dir, t_file *file, t_stat *st) {
    if (listxattr(dir->filename, NULL, 0, XATTR_NOFOLLOW) > 0 && ++st) {
        // file->fields.attr = mx_strnew(1024);
        // listxattr(dir->filename, file->fields.attr, 1024, XATTR_NOFOLLOW);
        // int l = getxattr(dir->filename, file->fields.attr,
        //                     NULL, 1024, 1024, XATTR_NOFOLLOW);
        // printf("%s : %i\n", file->fields.attr, l);
        ++file;

        // haven't done
        // need to concat l to attr
    }
}
