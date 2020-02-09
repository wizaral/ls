#pragma once

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
//#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>

#include "defines.h"
#include "errors.h"
#include "libmx.h"
#include "macro.h"
#include "structs.h"

void mx_parse(int argnum, char **argum);

void mx_error_nodir(char *argum);
void mx_error_usage();
void mx_nelegal(char flag);
