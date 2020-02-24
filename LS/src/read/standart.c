#include "uls.h"

struct dirent *mx_standart(t_dir *dir)  {
    struct dirent *drt;

    while (drt->d_name[0] = '.')
        readdir(dir->dir);
    return readdir(dir->dir);
}
