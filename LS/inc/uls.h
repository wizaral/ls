#pragma once

#include "defines.h"
#include "errors.h"
#include "libmx.h"
#include "macro.h"
#include "structs.h"

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <wchar.h>

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
