#include "uls.h"

// static inline void advanced_perm(t_dir *dir, t_file *file) {
//     acl_t acl;
//     char *path = mx_strjoin(dir->name, "/");

//     mx_strcat(path, dir->file->d_name);
//     acl = acl_get_file(path, ACL_TYPE_EXTENDED);
//     if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
//         file->fields.access[10] = '@';
//     if (acl) {
//         mx_strcat(file->fields.access, "+");
//         acl_free(acl);
//     }
//     mx_strdel(&path);
// }

static inline void basic_perm(char *access, t_stat *st) {
    static const char *str[] = {"-r", "-w", "-x", "sS", "tT"};

    MX_ISDIR(st->st_mode) ? (access[0] = 'd') : 0;
    MX_ISLNK(st->st_mode) ? (access[0] = 'l') : 0;
    MX_ISCHR(st->st_mode) ? (access[0] = 'c') : 0;
    MX_ISBLK(st->st_mode) ? (access[0] = 'b') : 0;
    MX_ISSOCK(st->st_mode) ? (access[0] = 's') : 0;
    MX_ISFIFO(st->st_mode) ? (access[0] = 'p') : 0;
    access[1] = str[0][(st->st_mode & S_IRUSR) > 0];
    access[2] = str[1][(st->st_mode & S_IWUSR) > 0];
    access[3] = str[2][(st->st_mode & S_IXUSR) > 0];
    access[4] = str[0][(st->st_mode & S_IRGRP) > 0];
    access[5] = str[1][(st->st_mode & S_IWGRP) > 0];
    access[6] = str[2][(st->st_mode & S_IXGRP) > 0];
    access[7] = str[0][(st->st_mode & S_IROTH) > 0];
    access[8] = str[1][(st->st_mode & S_IWOTH) > 0];
    access[9] = str[2][(st->st_mode & S_IXOTH) > 0];
    MX_ISUID(st->st_mode) ? (access[3] = str[3][access[3] == 'x']) : 0;
    MX_ISGID(st->st_mode) ? (access[6] = str[3][access[6] == 'x']) : 0;
    MX_ISVTX(st->st_mode) ? (access[9] = str[4][access[9] == 'x']) : 0;
}

void mx_access(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    file->fields.access[0] = '-';
    file->fields.access[11] = ' ';
    basic_perm(file->fields.access, st);
    // file->fields.access[10] = ' ';   // some code about @+
    // advanced_perm(dir, file);        // some code about @+
    ++info;
    ++dir;
}
