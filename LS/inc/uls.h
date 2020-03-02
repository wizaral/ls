#pragma once

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>

#include "defines.h"
#include "errors.h"
#include "libmx.h"
#include "macro.h"
#include "structs.h"

#include <sys/acl.h>

void mx_parse(t_info *info, int ac, char **av);
void mx_check_flags(t_info *info, t_vector *flags);

t_dirent *mx_full(t_dir *dir);
t_dirent *mx_hidden(t_dir *dir);
t_dirent *mx_standart(t_dir *dir);

void mx_write_1(t_dir *dir);
void mx_write_C(t_dir *dir);
void mx_write_l(t_dir *dir);
void mx_write_m(t_dir *dir);
void mx_write_x(t_dir *dir);

void mx_write_CG(t_dir *dir);
void mx_write_xG(t_dir *dir);

void mx_color(t_file *file);
void mx_nocolor(t_file *file);

int mx_compare_ascii(const void *a, const void *b);
int mx_compare_size(const void *a, const void *b);
int mx_compare_time(const void *a, const void *b);

void mx_access(t_dir *d, t_file *f, t_stat *s);
void mx_arrow(t_dir *dir, t_file *file, t_stat *st);
void mx_group(t_dir *dir, t_file *file, t_stat *st);
void mx_user(t_dir *dir, t_file *file, t_stat *st);
void mx_suffix(t_dir *d, t_file *f, t_stat *s);
void mx_time(t_dir *d, t_file *f, t_stat *s);
void mx_time_full(t_dir *d, t_file *f, t_stat *s);

void mx_not_printable(t_dir *dir, t_file *file, t_stat *st);
void mx_only_printable(t_dir *dir, t_file *file, t_stat *st);

char *mx_human_size(t_dir *dir, t_file *file, t_stat *st);
char *mx_size(t_dir *dir, t_file *file, t_stat *st);

void zaglushka(t_dir *d, t_file *f, t_stat *s);
