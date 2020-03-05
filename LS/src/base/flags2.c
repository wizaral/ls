#include "uls.h"

void mx_check_compare(t_info *info, char flag) {
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

void mx_check_other(t_info *info, char flag) {
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

static inline void accept_l(t_info *info, t_get *get) {
    info->print_total = mx_total;
    get->access = mx_access;
    get->links = mx_links;
    get->user == mx_dummy ? get->user = mx_user_name : mx_dummy;
    get->grp = mx_group;
    get->size == mx_dummy ? get->size = mx_size_b : mx_dummy;
    get->time == mx_dummy ? get->time = mx_time_short : mx_dummy;
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
        info->write == mx_write_C ? info->write = mx_write_CG : mx_write_C;
        info->write == mx_write_x ? info->write = mx_write_xG : mx_write_x;
    }
    if (info->write == mx_write_m || get->bsize == mx_dummy)
        info->print_total = mx_nototal;
    if (info->reverse) {
        info->cmp == mx_compare_ascii ? info->cmp = mx_compare_ascii_r : NULL;
        info->cmp == mx_compare_time ? info->cmp = mx_compare_time_r : NULL;
        info->cmp == mx_compare_size ? info->cmp = mx_compare_size_r : NULL;
    }
}
