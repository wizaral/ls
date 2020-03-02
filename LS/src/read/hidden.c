#include "uls.h"

t_dirent *mx_hidden(t_dir *dir) {
    t_dirent *drt = readdir(dir->dir);

    while (drt && drt->d_name[0] == '.' && (drt->d_name[1] == '\0'
        || (drt->d_name[1] == '.' && drt->d_name[2] == '\0')))
            drt = readdir(dir->dir);
    return drt;
}
