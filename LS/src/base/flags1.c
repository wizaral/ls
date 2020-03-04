#include "uls.h"

static inline void check_read(t_info *info, char flag) {
    if (info->read != mx_full)
        info->read = flag == 'A' ? mx_hidden : mx_full;
}

static inline void check_write(t_info *info, char flag) {
    if (flag == 'l')
        info->write = mx_write_l;
    else if (flag == '1')
        info->write = mx_write_1;
    else if (flag == 'm')
        info->write = mx_write_m;
    else if (flag == 'C')
        info->write = mx_write_C;
    else if (flag == 'x')
        info->write = mx_write_x;
}

static inline void check_suffix(t_get *get, char flag) {
    get->suffix = flag == 'F' ? mx_suffix_all : mx_suffix_dir;
}

static inline void check_time(t_info *info, char flag) {
    if (flag == 'c')
        info->time_type = change;
    else if (flag == 'U')
        info->time_type = creation;
    else if (flag == 'u')
        info->time_type = last_access;
}

void mx_check_flags(t_info *info, t_vector *flags) {
    // PRINT FLAGS
    // mx_printstrlen((char *)flags->arr, flags->size, 1);
    // mx_printchar('\n', 1);

    for (size_t i = 0; i < flags->size; ++i) {
        char flag = flags->arr[i];

        if (flag == 'a' || flag == 'A')
            check_read(info, flag);
        else if (MX_WRITE(flag))
            check_write(info, flag);
        else if (flag == 'F' || flag == 'p')
            check_suffix(&info->get, flag);
        else if (flag == 'c' || flag == 'U' || flag == 'u')
            check_time(info, flag);
        else if (flag == 'f' || flag == 'S' || flag == 't')
            mx_check_compare(info, flag);
        else if (flag == 'q' || flag == 'v' || flag == 'w')
            mx_check_name(&info->get, flag);
        else if (MX_LADDS(flag))
            mx_check_adds(info, &info->get, flag);
        else if (MX_OTHER(flag))
            mx_check_other(info, flag);
        else
            printf("WATAFAK IS THIS: \"%c\"!!!\n", flag);   // delete before deploy
    }
}
