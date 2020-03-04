#include "uls.h"

static inline void advanced_perm(t_dir *dir, t_file *file) {
    acl_t acl;
    char *path = mx_strjoin(dir->name, "/");

    mx_strcat(path, dir->file->d_name);
    acl = acl_get_file(path, ACL_TYPE_EXTENDED);
    if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
        file->fields.access[10] = '@';
    if (acl) {
        mx_strcat(file->fields.access, "+");
        acl_free(acl);
    }
    mx_strdel(&path);
}

static inline void basic_perm(char *access, t_stat *st) {
    static const char *str[] = {"-r", "-w", "-x"};

    access[0] = '-';
    MX_ISDIR(st->st_mode) ? (access[0] = 'd') : 0;
    MX_ISLNK(st->st_mode) ? (access[0] = 'l') : 0;
    MX_ISCHR(st->st_mode) ? (access[0] = 'c') : 0;
    MX_ISBLK(st->st_mode) ? (access[0] = 'b') : 0;
    MX_ISSOCK(st->st_mode) ? (access[0] = 's') : 0;
    MX_ISFIFO(st->st_mode) ? (access[0] = 'p') : 0;
    access[1] = str[0][st->st_mode & S_IRUSR];
    access[2] = str[1][st->st_mode & S_IWUSR];
    access[3] = str[2][st->st_mode & S_IXUSR];
    access[4] = str[0][st->st_mode & S_IRGRP];
    access[5] = str[1][st->st_mode & S_IWGRP];
    access[6] = str[2][st->st_mode & S_IXGRP];
    access[7] = str[0][st->st_mode & S_IROTH];
    access[8] = str[1][st->st_mode & S_IWOTH];
    access[9] = str[2][st->st_mode & S_IXOTH];
    st->st_mode & S_ISTXT ? access[9] = 't' : 0;
}

void mx_access(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    basic_perm(file->fields.access, st);
    advanced_perm(dir, file);
    ++info;
}
