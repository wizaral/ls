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
    // PRINT FLAGS
    // mx_printstrlen((char *)flags->arr, flags->size, 1);
    // mx_printchar('\n', 1);

    for (size_t i = 0; i < flags->size; ++i) {
        char flg = flags->arr[i];

        if ((flg == 'a' || flg == 'A') && info->read != mx_full)
            info->read = flg == 'A' ? mx_hidden : mx_full;
        else if (MX_WRITE(flg))
            check_write(info, flg);
        else if (flg == 'F' || flg == 'p')
            info->get.suffix = flg == 'F' ? mx_suffix_all : mx_suffix_dir;
        else if (flg == 'c' || flg == 'U' || flg == 'u')
            check_time(info, flg);
        else if (flg == 'f' || flg == 'S' || flg == 't')
            check_compare(info, flg);
        else if (flg == 'q' || flg == 'v' || flg == 'w')
            info->get.name = flg == 'q' ? mx_only_printable : mx_not_printable;
        else if (MX_LADDS(flg))
            mx_check_adds(info, &info->get, flg);
        else if (MX_OTHER(flg))
            check_other(info, flg);
        // else
        //     printf("WATAFAK IS THIS: \"%c\"!!!\n", flg);   // delete before deploy
    }
}
