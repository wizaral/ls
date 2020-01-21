#include "uls.h"

static void inline print_tabs_links(t_data *data ,t_info *info, char **str) {
    for (uint64_t i = 0; i < info->laccess - mx_strlen(data->access) + info->llinks - mx_strlen(data->links) + 1; i++) {
        mx_strcat(*str, " ");
    }
}

static void inline print_tabs_size(t_data *data ,t_info *info, char **str) {
    int64_t buf = mx_strlen(data->size);

    if (mx_get_substr_index(data->size, "0x") != -1)
        buf = info->lsize;

    for (uint64_t i = 0; i < info->lsize - buf + info->lgrp - mx_strlen(data->grp) + 2; i++) {
        mx_strcat(*str, " ");
    }
}

static void inline print_tabs_grp(t_data *data ,t_info *info, char **str) {
    if ((int64_t)mx_strlen(data->login) == info->llogin)
            mx_strcat(*str, "  ");
    else 
        for (uint64_t i = 0; i < info->llogin - mx_strlen(data->login) + 2; i++)
            mx_strcat(*str, " ");
}

static char *create_string(t_data *data, t_info *info) {
    char *str = mx_strnew(256);

    mx_strcat(str, data->access);
    print_tabs_links(data, info, &str);
    mx_strcat(str, data->links);
    mx_strcat(str, " ");
    mx_strcat(str, data->login);
    print_tabs_grp(data, info, &str);
    mx_strcat(str, data->grp);
    print_tabs_size(data, info, &str);
    mx_strcat(str, data->size);
    mx_strcat(mx_strcat(str, " "), data->time);
    mx_strcat(mx_strcat(mx_strcat(str, " "), data->ent->d_name), "\n");

    return str;
}

void mx_print_l_flag(t_vector *file_vect, t_info *info) {
    t_data *data;
    char *str = NULL;

    mx_set_longest_fields(file_vect, info);

    printf("total %llu\n", info->total);
    for (size_t i = 0; i < file_vect->size; i++) {
        data = mx_at(file_vect, i);
        str = create_string(data, info);
        mx_printstr(str, 1);
        free(str);
    }
}
