#include "uls.h"

static int cmp(t_cv *e1, t_cv *e2) {
    return mx_strcmp(((const t_data *)e1)->ent->d_name,
                    ((const t_data *)e2)->ent->d_name);
}

void mx_uls(char *arg, t_info *info) {
    t_data *data = (t_data *)malloc(sizeof(t_data));
    DIR *dir;
    t_vector *file_vect = mx_create_vector(sizeof(t_data));

    if ((dir = opendir(arg)) != NULL) {
        while ((data->ent = readdir(dir)) != NULL) {
            stat(data->ent->d_name, data->st);
            lstat(data->ent->d_name, data->st);
            mx_push_backward(file_vect, data);
        }
        mx_l_flag(file_vect);
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
