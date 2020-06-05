#include "uls.h"

t_dirent *mx_hidden(DIR *dir) {
    t_dirent *drt = readdir(dir);

    while (drt && MX_DOTS(drt->d_name)) {
        drt = readdir(dir);
    }
    return drt;
}
