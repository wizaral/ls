#include "uls.h"

static inline void check_compare(t_info *info, char flag) {
    if (info->cmp != NULL) {
        if (flag == 'f') {
            info->cmp = NULL;
            info->read = mx_full;
        }
        else if (flag == 'S')
            info->cmp = mx_compare_size;
        else if (info->cmp != mx_compare_size)
            info->cmp = mx_compare_time;
    }
}

static inline void check_write(t_info *info, char flag) {
    if (flag == 'l')
        info->write = mx_write_l;
    else if (flag == '1')
        info->write = mx_write_1;
    else if (flag == 'm')
        info->write = mx_write_m;
    else if (flag == 'C' && info->write != mx_write_m)
        info->write = mx_write_C;
    else if (flag == 'x' && info->write != mx_write_m)
        info->write = mx_write_x;
}

static inline void check_time(t_info *info, char flag) {
    if (flag == 'c')
        info->time_type = change;
    else if (flag == 'U')
        info->time_type = creation;
    else if (flag == 'u')
        info->time_type = last_access;
}

static inline void check_other(t_info *info, char flag) {
    if (flag == 'i')
        info->get.inode = mx_inode;
    else if (flag == 's') {
        info->get.bsize = mx_bsize;
        info->print_total = mx_total;
    }
    else if (flag == 'G')
        info->print_name = info->output_dst ? mx_nocolor : mx_color;
    else if (flag == 'r')
        info->reverse = info->cmp;
    else
        info->recursion = mx_recursion;
}

void mx_check_flags(t_info *info, t_vector *flags) {
    for (size_t i = 0; i < flags->size; ++i) {
        char flag = flags->arr[i];

        if ((flag == 'a' || flag == 'A') && info->read != mx_full)
            info->read = flag == 'A' ? mx_hidden : mx_full;
        else if (MX_WRITE(flag))
            check_write(info, flag);
        else if (flag == 'F' || flag == 'p')
            info->get.suffix = flag == 'F' ? mx_suffix_all : mx_suffix_dir;
        else if (flag == 'c' || flag == 'U' || flag == 'u')
            check_time(info, flag);
        else if (flag == 'f' || flag == 'S' || flag == 't')
            check_compare(info, flag);
        else if (MX_PRINT(flag))
            mx_check_print(&info->get, flag);
        else if (MX_LADDS(flag))
            mx_check_adds(info, &info->get, flag);
        else if (MX_OTHER(flag))
            check_other(info, flag);
    }
}
