#include "uls.h"

static char *check_minor(unsigned int rdev) {
    char *minor;

    minor = mx_itoa(rdev & 0xffffff);
    if ((rdev & 0xffffff) > 256) {
        free(minor);
        minor = mx_nbr_to_hex(rdev & 0xffffff);
        while (mx_strlen(minor) < 10) {
            char *tmp_str = mx_strdup(minor);

            free(minor);
            minor = mx_strjoin("0", tmp_str);
            free(tmp_str);
        }
        minor[1] = 'x';
    }
    return minor;
}

static char *get_major(unsigned int rdev) {
    char *major = mx_itoa((rdev >> 24) & 0xff);

    while (mx_strlen(major) < 3) {
        char *tmp_str = mx_strjoin(" ", major);
        free(major);
        major = tmp_str;
    }
    return major;
}

static char *get_minor(unsigned int rdev) {
    char *minor = check_minor(rdev);

    while (mx_strlen(minor) < 3) {
        char *tmp_str = NULL;

        tmp_str = mx_strjoin(" ", minor);
        free(minor);
        minor = mx_strdup(tmp_str);
        free(tmp_str);
    }
    return minor;
}

char *mx_sym_num(char access, struct stat buff) {
    char *sym_num = NULL;
    char *major = NULL;
    char *minor = NULL;

    if (access == 'b' || access == 'c') {
        sym_num = get_major(buff.st_rdev);
        major = mx_strjoin(sym_num, ", ");
        free(sym_num);
        minor = get_minor(buff.st_rdev);
        sym_num = mx_strjoin(major, minor);
        free(major);
        free(minor);
    }
    else
        sym_num = mx_itoa(buff.st_size);
    return sym_num;
}
