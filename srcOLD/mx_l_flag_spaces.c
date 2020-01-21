#include "uls.h"

static void set_longest_links_num_and_access(t_vector *vect, t_info *info) {
    t_data *data = NULL;
    size_t longest = 0;
    size_t longestaccess = 0;

    for (size_t i = 0; i < vect->size; i++) {
        data = mx_at(vect, i);

        if (mx_strlen(data->links) > longest)
            longest = mx_strlen(data->links);
        if (mx_strlen(data->access) > longestaccess)
            longestaccess = mx_strlen(data->access);
    }
    info->llinks = longest;
    info->laccess = longestaccess;
}

static void set_longest_login(t_vector *vect, t_info *info) {
    t_data *data = NULL;
    size_t longest = 0;

    for (size_t i = 0; i < vect->size; i++) {
        data = mx_at(vect, i);

        if (mx_strlen(data->login) > longest)
            longest = mx_strlen(data->login);
    }
    info->llogin = longest;
}

static void set_longest_grp(t_vector *vect, t_info *info) {
    t_data *data = NULL;
    size_t longest = 0;

    for (size_t i = 0; i < vect->size; i++) {
        data = mx_at(vect, i);

        if (mx_strlen(data->grp) > longest)
            longest = mx_strlen(data->grp);
    }
    info->lgrp = longest;
}

static void set_longest_size(t_vector *vect, t_info *info) {
    t_data *data = NULL;
    size_t longest = 0;

    for (size_t i = 0; i < vect->size; i++) {
        data = mx_at(vect, i);

        if (mx_strlen(data->size) > longest && mx_get_substr_index(data->size, "0x") == -1)
            longest = mx_strlen(data->size);
    }
    info->lsize = longest;
}

void mx_set_longest_fields(t_vector *vect, t_info *info) {
    set_longest_links_num_and_access(vect, info);
    set_longest_login(vect, info);
    set_longest_grp(vect, info);
    set_longest_size(vect, info);
}
