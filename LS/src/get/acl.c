#include "uls.h"

static inline void advanced_perm(t_dir *dir, t_file *file, struct stat *st) {
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

void mx_get_acl(t_dir *dir, t_file *file, struct stat *st) {
    advanced_perm(dir, file, st);
}
