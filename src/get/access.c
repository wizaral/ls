#include "uls.h"

static inline void basic_perm(char *access, t_stat *st) {
    static const char *str[] = {"-r", "-w", "-x", "Ss", "Tt"};

    MX_ISDIR(st->st_mode) ? (access[0] = 'd') : 0;
    MX_ISLNK(st->st_mode) ? (access[0] = 'l') : 0;
    MX_ISCHR(st->st_mode) ? (access[0] = 'c') : 0;
    MX_ISBLK(st->st_mode) ? (access[0] = 'b') : 0;
    MX_ISSCK(st->st_mode) ? (access[0] = 's') : 0;
    MX_ISFIF(st->st_mode) ? (access[0] = 'p') : 0;
    access[1] = str[0][(st->st_mode & S_IRUSR) != 0];
    access[2] = str[1][(st->st_mode & S_IWUSR) != 0];
    access[3] = str[2][(st->st_mode & S_IXUSR) != 0];
    access[4] = str[0][(st->st_mode & S_IRGRP) != 0];
    access[5] = str[1][(st->st_mode & S_IWGRP) != 0];
    access[6] = str[2][(st->st_mode & S_IXGRP) != 0];
    access[7] = str[0][(st->st_mode & S_IROTH) != 0];
    access[8] = str[1][(st->st_mode & S_IWOTH) != 0];
    access[9] = str[2][(st->st_mode & S_IXOTH) != 0];
    MX_ISUID(st->st_mode) ? (access[3] = str[3][access[3] == 'x']) : 0;
    MX_ISGID(st->st_mode) ? (access[6] = str[3][access[6] == 'x']) : 0;
    MX_ISVTX(st->st_mode) ? (access[9] = str[4][access[9] == 'x']) : 0;
}

static char get_attr_acl(t_dir *dir) {
    ssize_t attr = listxattr(dir->filename, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = NULL;

    if (attr > 0)
        return '@';

    if ((acl = acl_get_file(dir->filename, ACL_TYPE_DEFAULT))
        || (acl = acl_get_link_np(dir->filename, ACL_TYPE_EXTENDED))) {
        acl_free(acl);
        return '+';
    }
    return ' ';
}

void mx_access(t_dir *dir, t_file *file, t_stat *st) {
    file->fields.access[0] = '-';
    basic_perm(file->fields.access, st);
    file->fields.access[10] = get_attr_acl(dir);
    file->fields.access[11] = ' ';
}
