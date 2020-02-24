#include "uls.h"

struct dirent *mx_standart(t_dir *dir)  {
    struct dirent *drt = readdir(dir->dir);

    while (drt && drt->d_name[0] == '.')
        drt = readdir(dir->dir);
    return drt;
}
