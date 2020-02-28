#include "uls.h"

static inline void basic_perm(char *access, struct stat *st) {
    access[0] = S_ISDIR(st->st_mode) ? 'd' : '-';
    access[0] = S_ISLNK(st->st_mode) ? 'l' : access[0];
    access[0] = S_ISCHR(st->st_mode) ? 'c' : access[0];
    access[0] = S_ISBLK(st->st_mode) ? 'b' : access[0];
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
    basic_perm(&file->fields.access, st);
}
