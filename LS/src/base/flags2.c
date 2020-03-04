#include "uls.h"

void mx_check_sort(t_info *info, char flag) {
    if (info->cmp != NULL) {        // мейби даже тут не скомпилит я хз еси шо))0)
        if (flag == 'f') {
            info->cmp = NULL;       // may not compile. сверху бахни функу-затычку если шоя потом порешаю
            info->read = mx_full;
        }
        else if (flag == 'S')
            info->cmp = mx_compare_size;
        else if (info->cmp != mx_compare_size)
            info->cmp = mx_compare_time;
    }
}

void mx_check_name(t_get *get, char flag) {
    get->name = flag == 'q' ? mx_only_printable : mx_not_printable;
}

void mx_check_adds(t_info *info, t_get *get, char flag) {
    if (flag == 'g' || flag == 'n') {
        info->write = mx_write_l;
        if (flag == 'n' && get->user != mx_user_skip)
            get->user = mx_user_id;
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
    else if (flag == 's')
        info->get.bsize = mx_bsize;
    else if (flag == 'G')
        info->print_name = info->output_dst ? mx_nocolor : mx_color;
    else if (flag == 'r')
        info->foreach = mx_foreach_vector_reverse;
    else
        info->recursion = mx_recursion;
}

void mx_minimize_flags(t_info *info) {
    if (info->write == mx_write_l) {
        get->access = mx_access;
        get->links = mx_links;
        get->user == mx_dummy ? get->user = mx_user_name : mx_dummy;
        get->grp = mx_group;
        get->size == mx_dummy ? get->size = mx_size_b : mx_dummy;
        get->time == mx_dummy ? get->time = mx_time_short : mx_dummy;
        get->arrow = mx_arrow;
    }
    else {
        get->access = get->links = get->user = get->grp = mx_dummy;
        get->flags = get->size = get->time = get->arrow = mx_dummy;
        get->attr = get->acl = mx_dummy;
    }
}
