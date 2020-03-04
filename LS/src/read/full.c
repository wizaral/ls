#include "uls.h"

t_dirent *mx_full(DIR *dir) {
    return readdir(dir);
}
