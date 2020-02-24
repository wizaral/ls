#include "uls.h"

struct dirent *mx_hidden(t_dir *dir) {
    readdir(dir->dir);
    readdir(dir->dir);
    return readdir(dir->dir);
}
