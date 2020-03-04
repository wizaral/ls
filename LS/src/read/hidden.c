#include "uls.h"

t_dirent *mx_hidden(DIR *dir) {
    t_dirent *drt = readdir(dir);

    while (drt && drt->d_name[0] == '.' && (drt->d_name[1] == '\0'
        || (drt->d_name[1] == '.' && drt->d_name[2] == '\0')))
            drt = readdir(dir);
    return drt;
}
