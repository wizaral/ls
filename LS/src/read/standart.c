#include "uls.h"

t_dirent *mx_standart(t_dir *dir)  {
    t_dirent *drt = readdir(dir->dir);

    while (drt && drt->d_name[0] == '.')
        drt = readdir(dir->dir);
    return drt;
}
