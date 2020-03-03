#include "uls.h"

// void mx_get_acl(t_dir *dir, t_file *file, t_stat *st) {
//     advanced_perm(dir, file, st);
// }

                                        // то что снизу писал в отдельном мейне
                                        // поэтому без прототипа и тд
                                        // короче я ебу как это дописывать пока
    // acl_t acl;
    // char **acl_text;
    // char **splited;
    
    // acl = acl_get_file(av[1], ACL_TYPE_EXTENDED);
    // acl_text = mx_strsplit(acl_to_text(acl, NULL), '\n');
    
    // for (int i = 1; acl_text[i]; ++i) {
    //     splited = mx_strsplit(acl_text[i], ':');
    //     for (int j = 0; splited[j]; ++j) {
    //         if (j == 0)   
    //             printf(" %d: %s:", i - 1, splited[j]);
    //         else if (j == 1 || j == 3) {}
    //         else if (splited[j + 1])
    //             printf("%s ", splited[j]);
    //         else
    //             printf("%s\n", splited[j]);
    //     }
    // }
    // acl_free(acl);