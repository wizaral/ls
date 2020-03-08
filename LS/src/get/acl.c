#include "uls.h"

void mx_acl(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    acl_t acl = acl_get_file(dir->filename, ACL_TYPE_EXTENDED);

    if (acl) {
        file->fields.acl = acl_to_text(acl, NULL);
        acl_free(acl);
        // printf("%s\n", file->fields.acl);
        // haven't done. need good text
    }
    ++info;
    ++st;
}
