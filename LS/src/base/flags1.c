#include "uls.h"

static inline void check_read_type(t_info *info, char flag) {
    if (info->read != mx_full)
        info->read = flag == 'A' ? mx_hidden : mx_full;
}

static inline void check_write_type(t_info *info, char flag) {
    if (flag == 'l') {
        info->write = mx_write_l;
        info->get.size = mx_size;
        info->get.access = mx_access;
        info->get.suffix = mx_suffix;
        info->get.arrow = mx_arrow;
        info->get.grp = mx_group;
        info->get.time = mx_time;
        info->get.user = mx_user;
    }
    if (flag == '1')
        info->write = mx_write_1;
    if (flag == 'm')
        info->write = mx_write_m;
    if (flag == 'C')
        info->write = mx_write_C;
    if (flag == 'x')
        info->write = mx_write_x;
}

static inline void check_suffix_type(t_info *info, char flag) {
    info->write = flag == 'F' ? zaglushka : zaglushka;
}

static inline void check_time_type(t_info *info, char flag) {
    if (flag == 'c')
        info->time_type = change;
    else if (flag == 'U')
        info->time_type = creation;
    else if (flag == 'u')
        info->time_type = last_access;
}

void mx_check_flags(t_info *info, t_vector *flags) {
    // mx_printstrlen((char *)flags->arr, flags->size, 1);
    for (size_t i = 0; i < flags->size; ++i) {
        char flag = flags->arr[i];

        if (flag == 'a' || flag == 'A')
            check_read_type(info, flag);
        else if (MX_WRITE(flag))
            check_write_type(info, flag);
        else if (flag == 'F' || flag == 'p')
            check_suffix_type(info, flag);
        else if (flag == 'c' || flag == 'U' || flag == 'u')
            check_time_type(info, flag);
        else if (flag == 'f' || flag == 'S' || flag == 't')
            mx_check_sort_type(info, flag);
        else if (flag == 'q' || flag == 'v' || flag == 'w')
            mx_check_name_type(info, flag);
        else if (MX_LADDS(flag))
            mx_check_adds_type(info, flag);
        else if (MX_OTHER(flag))
            mx_check_other_type(info, flag);
    }
}
