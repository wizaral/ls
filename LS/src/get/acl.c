#include "uls.h"

void mx_acl(t_dir *dir, t_file *file, t_stat *st) {
    // acl_t acl1 = acl_get_file(dir->filename, ACL_TYPE_EXTENDED);
    // acl_t acl2 = acl_get_file(dir->filename, 0);
    // acl_t acl3 = acl_get_file(dir->filename, 1);

    // if (acl1) {
    //     // file->fields.acl = acl_to_text(acl1, NULL);
    //     char *acl = acl_to_text(acl1, NULL);

    //     acl_free(acl1);
    //     printf("1 %s\n", acl);
    //     free(acl);
    // }
    // if (acl2) {
    //     // file->fields.acl = acl_to_text(acl2, NULL);
    //     char *acl = acl_to_text(acl2, NULL);

    //     acl_free(acl2);
    //     printf("2 %s\n", acl);
    //     free(acl);
    // }
    // if (acl3) {
    //     // file->fields.acl = acl_to_text(acl2, NULL);
    //     char *acl = acl_to_text(acl3, NULL);

    //     acl_free(acl3);
    //     printf("3 %s\n", acl);
    //     free(acl);
    // }
    ++dir;
    ++st;
    ++file;
}
