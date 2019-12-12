#include "uls.h"

static int cmp(t_cv *e1, t_cv *e2) {
    return mx_strcmp(((const t_dir *)e1)->d_name, ((const t_dir *)e2)->d_name);
}

void mx_uls(char *arg, t_info *info) {
    DIR *dir;
    t_dir *ent;
    t_vector *file_vect = mx_create_vector(sizeof(t_dir));

    if ((dir = opendir(arg)) != NULL) {
        while ((ent = readdir(dir)) != NULL)
            mx_push_backward(file_vect, ent);
        mx_quicksort(file_vect->arr, file_vect->size, file_vect->bytes, cmp);
        mx_num_of_cols(file_vect, info);
        basic_print(file_vect, info);
        closedir(dir);
    }
    else {
        perror("");
        return;
    }
}
