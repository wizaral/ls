#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include "defines.h"
#include "errors.h"
#include "macroses.h"
#include "structs.h"
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

t_file *mx_create_file_node(struct dirent *ent);
void mx_push_file_back(t_file **file_list, struct dirent *ent);
void mx_push_file_front(t_file **file_list, struct dirent *ent);
void mx_sort_file_list(t_file *lst);
void mx_pop_file_list_back(t_file **head);
void mx_clear_file_list(t_file *list);
int mx_file_list_size(t_file *list);

/*
* PRINT FUNC
*/

void mx_print_w_flags(t_file *file_list);

#endif
