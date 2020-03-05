#include "uls.h"

void mx_check_adds(t_info *info, t_get *get, char flag) {
    if (flag == 'g' || flag == 'n') {
        info->write = mx_write_l;
        if (flag == 'n' && get->user != mx_user_skip)
            get->user = mx_user_id;
        else
            get->user = mx_user_skip;
    }
    else if (flag == 'O')
        get->flags = mx_file_flags;
    else if (flag == 'h')
        get->size = mx_size_h;
    else if (flag == 'T')
        get->time = mx_time_full;
    else if (flag == '@')
        get->attr = mx_attr;
    else
        get->acl = mx_acl;
}

static inline void accept_l(t_info *info, t_get *get) {
    info->print_total = mx_total;
    get->access = mx_access;
    get->links = mx_links;
    get->user == mx_dummy ? get->user = mx_user_name : NULL;
    get->grp = mx_group;
    get->size == mx_dummy ? get->size = mx_size_b : NULL;
    get->time == mx_dummy ? get->time = mx_time_short : NULL;
    get->arrow = mx_arrow;
}

void mx_minimize_flags(t_info *info, t_get *get) {
    if (info->write == mx_write_l)
        accept_l(info, get);
    else {
        get->access = get->links = get->user = get->grp = get->attr = mx_dummy;
        get->flags = get->size = get->time = get->arrow = get->acl = mx_dummy;
    }
    if (info->print_name == mx_color) {
        info->write == mx_write_C ? info->write = mx_write_CG : NULL;
        info->write == mx_write_x ? info->write = mx_write_xG : NULL;
    }
    if (info->write == mx_write_m || get->bsize == mx_dummy)
        info->print_total = mx_nototal;
    if (info->reverse && info->cmp) {
        info->cmp == mx_compare_ascii ? info->cmp = mx_compare_ascii_r : NULL;
        info->cmp == mx_compare_time ? info->cmp = mx_compare_time_r : NULL;
        info->cmp == mx_compare_size ? info->cmp = mx_compare_size_r : NULL;
    }
}
