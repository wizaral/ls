#include "uls.h"

static inline void advanced_perm(t_dir *dir, t_file *file) {
    acl_t acl;
    char *path = mx_strjoin(dir->name, "/");

    mx_strcat(path, file->fields.name);                       // АХТУНГ ЕСЛИ АКСЕС ВЫЗЫВАЕТСЯ КАК ПЕРВЫЙ ГЕТТЕР
                                                              // ТО ОН НЕ НАЙДЁТ ИМЯ И УМРЁТ, А ДЛЯ ACL
    acl = acl_get_file(path, ACL_TYPE_EXTENDED);              // НУЖЕН ПУТЬ(походу) ТАК ШО ВООТ
    if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
        file->fields.access[10] = '@';
    if (acl) {
        mx_strcat(file->fields.access, "+");
        acl_free(acl);
    }
    mx_strdel(&path);
}

static inline void basic_perm(char *access, struct stat *st) {
    access[0] = MX_ISDIR(st->st_mode) ? 'd' : '-';
    access[0] = MX_ISLNK(st->st_mode) ? 'l' : access[0];
    access[0] = MX_ISCHR(st->st_mode) ? 'c' : access[0];
    access[0] = MX_ISBLK(st->st_mode) ? 'b' : access[0];
    access[0] = MX_ISSOCK(st->st_mode) ? 's' : access[0];
    access[0] = MX_ISFIFO(st->st_mode) ? 'p' : access[0];
    access[1] = st->st_mode & S_IRUSR ? 'r' : '-';
    access[2] = st->st_mode & S_IWUSR ? 'w' : '-';
    access[3] = st->st_mode & S_IXUSR ? 'x' : '-';
    access[4] = st->st_mode & S_IRGRP ? 'r' : '-';
    access[5] = st->st_mode & S_IWGRP ? 'w' : '-';
    access[6] = st->st_mode & S_IXGRP ? 'x' : '-';
    access[7] = st->st_mode & S_IROTH ? 'r' : '-';
    access[8] = st->st_mode & S_IWOTH ? 'w' : '-';
    access[9] = st->st_mode & S_IXOTH ? 'x' : '-';
    st->st_mode & S_ISTXT ? access[9] = 't' : 0;
}

void mx_get_access(t_dir *dir, t_file *file, struct stat *st) {
    basic_perm(file->fields.access, st);
    advanced_perm(dir, file);
    ++dir;  // for no warnings
}
