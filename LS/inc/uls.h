#pragma once

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

void mx_parse(int argnum, char *argum[]);

/*
* ERRORS
*/

void mx_error_nodir(char *argum);
void mx_error_usage();
void mx_nelegal(char flag);

// void mx_uls(char *arg, t_info *info);
// t_file *mx_create_file_node(struct dirent *ent);

/*
* PRINT FUNC
*/

//void mx_print_w_flags(t_vector *file_vect);


/*
*   PRINT CALC
*/

// void mx_num_of_cols(t_vector *file_vect, t_info *info);

/*
*   FLAG
*/

// void mx_advanced_permissions_check(t_vector *vec, t_info *info);
// void mx_basic_permissions(t_vector *vec);
// void mx_l_flag(t_vector *vec, t_info *info);
// char *mx_sym_num(char access, struct stat buff);
// void mx_set_longest_fields(t_vector *vect, t_info *info);
// void mx_print_l_flag(t_vector *file_vect, t_info *info);
