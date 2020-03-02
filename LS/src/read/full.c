#include "uls.h"

struct dirent *mx_full(t_dir *dir) {
    return readdir(dir->dir);
}
