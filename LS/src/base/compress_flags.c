#include "uls.h"

void mx_check_adds(t_info *info, t_get *get, char flag) {
    if (flag == 'g' || flag == 'n' || flag == 'o') {
        info->write = mx_write_l;
        if (flag == 'o')
            get->grp = mx_grp_skip;
        else if (flag == 'n' && get->user != mx_user_skip)
            get->user = mx_user_id;
        else
            get->user = mx_user_skip;
    }
    else
        get->time = mx_time_full;
}

static inline void accept_l(t_info *info, t_get *get) {
    info->print_total = mx_total;
    info->time_len = get->time == mx_time_full ? 20 : 12;
    get->access = mx_access;
    get->links = mx_links;
    get->user == mx_dummy ? get->user = mx_user_name : NULL;
    get->grp == mx_dummy ? get->grp = mx_grp_name : NULL;
    get->size == mx_dummy ? get->size = mx_size_b : NULL;
    get->time == mx_dummy ? get->time = mx_time_short : NULL;
    get->arrow = mx_arrow;
}

void mx_compress_flags(t_info *info, t_get *get) {
    if (info->write == mx_write_l)
        accept_l(info, get);
    else {
        get->access = get->links = get->user = get->grp = mx_dummy;
        get->size = get->time = get->arrow = mx_dummy;
    }
    if (info->print_name == mx_color) {
        info->write == mx_write_C ? info->write = mx_write_CG : NULL;
        info->write == mx_write_x ? info->write = mx_write_xG : NULL;
        info->get.access = mx_access;
    }
    if ((get->bsize == mx_dummy && info->write != mx_write_l)
        || info->write == mx_write_m)
        info->print_total = mx_nototal;
    if (info->reverse && info->cmp) {
        info->cmp == mx_compare_ascii ? info->cmp = mx_compare_ascii_r : NULL;
        info->cmp == mx_compare_time ? info->cmp = mx_compare_time_r : NULL;
        info->cmp == mx_compare_size ? info->cmp = mx_compare_size_r : NULL;
    }
}
