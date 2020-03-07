#include "uls.h"

bool mx_check_block_char(const char *name) {
    DIR *dir = opendir(name);
    t_stat st;

    for (t_dirent *f = readdir(dir); f; f = readdir(dir)) {
        lstat(f->d_name, &st);
        if (MX_ISBLK(st.st_mode) || MX_ISCHR(st.st_mode)) {
            closedir(dir);
            return true;
        }
    }
    closedir(dir);
    return false;
}
