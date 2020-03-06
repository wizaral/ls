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
void mx_check_adds(t_info *info, t_get *get, char flag);
void mx_compress_flags(t_info *info, t_get *get);

void mx_process_args(t_info *info);
void mx_process_dir(t_info *info, char *name);

void mx_uls(t_info *info, t_dir *dir);
void mx_recursion(t_info *info, t_dir *dir);

size_t mx_get_inode_bsize_len(t_offset *off);
void mx_make_inode_bsize(t_offset *off, char *str, t_printable *print, t_lengths *len);
uint16_t mx_winsize(t_info *info);
char *mx_get_path_name(char *path, size_t plen, char *name, size_t nlen);

t_dirent *mx_full(DIR *dir);        // -a
t_dirent *mx_hidden(DIR *dir);      // -A
t_dirent *mx_standart(DIR *dir);    // default

void mx_write_1(t_info *info, t_dir *dir);  // -1
void mx_write_C(t_info *info, t_dir *dir);  // -C
void mx_write_l(t_info *info, t_dir *dir);  // -l
void mx_write_m(t_info *info, t_dir *dir);  // -m
void mx_write_x(t_info *info, t_dir *dir);  // -x

void mx_write_CG(t_info *info, t_dir *dir); // -C -G
void mx_write_xG(t_info *info, t_dir *dir); // -x -G

void mx_color(t_file *file);    // -G
void mx_nocolor(t_file *file);  // default or to file

void mx_total(t_info *info, t_dir *dir);    // -l | -s
void mx_nototal(t_info *info, t_dir *dir);  // -m | default

int mx_compare_ascii(const void *a, const void *b); // default
int mx_compare_size(const void *a, const void *b);  // -S
int mx_compare_time(const void *a, const void *b);  // -t

int mx_compare_ascii_r(const void *a, const void *b); // -r
int mx_compare_size_r(const void *a, const void *b);  // -S -r
int mx_compare_time_r(const void *a, const void *b);  // -t -r

/*
 * full list of getters
 * all of them just creating string with some file information for print
 * they can't update any structs of global state or current directory
*/

void mx_inode(t_info *info, t_dir *dir, t_file *file, t_stat *st);              // -i
void mx_bsize(t_info *info, t_dir *dir, t_file *file, t_stat *st);              // -s

void mx_access(t_info *info, t_dir *dir, t_file *file, t_stat *st);             // -l
void mx_links(t_info *info, t_dir *dir, t_file *file, t_stat *st);              // -l

void mx_user_id(t_info *info, t_dir *dir, t_file *file, t_stat *st);            // -n(l)
void mx_user_name(t_info *info, t_dir *dir, t_file *file, t_stat *st);          // -l
void mx_user_skip(t_info *info, t_dir *dir, t_file *file, t_stat *st);          // -g(l)
void mx_group(t_info *info, t_dir *dir, t_file *file, t_stat *st);              // -l

void mx_file_flags(t_info *info, t_dir *dir, t_file *file, t_stat *st);         // -O -l

void mx_size_h(t_info *info, t_dir *dir, t_file *file, t_stat *st);             // -h -l
void mx_size_b(t_info *info, t_dir *dir, t_file *file, t_stat *st);             // -l

void mx_time_short(t_info *info, t_dir *dir, t_file *file, t_stat *st);         // -l
void mx_time_full(t_info *info, t_dir *dir, t_file *file, t_stat *st);          // -T -l

void mx_not_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st);      // -v -w
void mx_only_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st);     // -q

void mx_suffix_all(t_info *info, t_dir *dir, t_file *file, t_stat *st);         // -F
void mx_suffix_dir(t_info *info, t_dir *dir, t_file *file, t_stat *st);         // -p

void mx_arrow(t_info *info, t_dir *dir, t_file *file, t_stat *st);              // -l
void mx_attr(t_info *info, t_dir *dir, t_file *file, t_stat *st);               // -@
void mx_acl(t_info *info, t_dir *dir, t_file *file, t_stat *st);                // -e

void mx_dummy(t_info *info, t_dir *dir, t_file *file, t_stat *st);             // do nothing
