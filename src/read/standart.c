#include "uls.h"

t_dirent *mx_standart(DIR *dir)  {
    t_dirent *drt = readdir(dir);

    while (drt && drt->d_name[0] == '.') {
        drt = readdir(dir);
    }
    return drt;
}
