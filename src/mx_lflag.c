#include "uls.h"

void mx_advanced_permissions_check(t_vector *vec) {
    acl_t acl;
    t_data *data;

    for (t_ull i = 0; i < vec->size; i++) {
        data = mx_at(vec, i);
        acl = acl_get_file(data->ent->d_name, ACL_TYPE_EXTENDED);
        if (acl) {
            mx_strcat(data->access, "+");
            acl_free(acl);
        }
    }
}

void mx_basic_permissions(t_vector *vec) {
    int j = 0;
    t_data *data;

    for (t_ull i = 0; i < vec->size; i++) {
        data = mx_at(vec, i);
        data->access = mx_strnew(14);
        data->access[j++] = S_ISDIR(data->st->st_mode) ? 'd' : '-';
        data->access[j++] = data->st->st_mode & S_IRUSR ? 'r' : '-';
        data->access[j++] = data->st->st_mode & S_IWUSR ? 'w' : '-';
        data->access[j++] = data->st->st_mode & S_IXUSR ? 'x' : '-';
        data->access[j++] = data->st->st_mode & S_IRGRP ? 'r' : '-';
        data->access[j++] = data->st->st_mode & S_IWGRP ? 'w' : '-';
        data->access[j++] = data->st->st_mode & S_IXGRP ? 'x' : '-';
        data->access[j++] = data->st->st_mode & S_IROTH ? 'r' : '-';
        data->access[j++] = data->st->st_mode & S_IWOTH ? 'w' : '-';
        data->access[j++] = data->st->st_mode & S_IXOTH ? 'x' : '-';
        j = 0;
    }
}

void mx_l_flag(t_vector *vec) {
    mx_basic_permissions(vec);
    mx_advanced_permissions_check(vec);
}
