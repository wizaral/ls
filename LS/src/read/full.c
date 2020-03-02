#include "uls.h"

t_dirent *mx_full(t_dir *dir) {
    return readdir(dir->dir);
}
