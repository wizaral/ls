#include "uls.h"

void mx_uls(char *arg) {
    DIR *dir;
    struct dirent *ent;
    t_file *file_list = NULL;

    if ((dir = opendir(arg)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            mx_push_file_front(&file_list, ent);
        }
        mx_sort_file_list(file_list);
        mx_print_w_flags(file_list);
        mx_clear_file_list(file_list);
        closedir(dir);
    }
    else {
        perror("");
        return;
    }
}
