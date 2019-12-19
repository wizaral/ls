#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include "defines_ls.h"
#include "errors_ls.h"
#include "macroses_ls.h"
#include "structs_ls.h"
#include "types_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <wchar.h>
#include <pwd.h>
#include <grp.h>

/*
* FILE LIST
*/

void mx_uls(char *arg, t_info *info);
t_file *mx_create_file_node(struct dirent *ent);

/*
* PRINT FUNC
*/

//void mx_print_w_flags(t_vector *file_vect);
void basic_print(t_vector *file_vect, t_info *info);

/*
*   PRINT CALC
*/

void mx_num_of_cols(t_vector *file_vect, t_info *info);

/*
*   FLAG
*/

void mx_advanced_permissions_check(t_vector *vec);
void mx_basic_permissions(t_vector *vec);
void mx_l_flag(t_vector *info);

#endif
