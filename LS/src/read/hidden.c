#include "uls.h"

struct dirent *mx_hidden(t_dir *dir) {
    readdir(dir->dir);
    readdir(dir->dir);
    dir->info->read = mx_full;
    return readdir(dir->dir);
}
