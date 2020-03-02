#include "uls.h"

mx_check_sort_type(t_info *info, char flag) {
    if (info->cmp != NULL) {
        if (flag == 'f')
            info->cmp = NULL;
        else if (flag == 'S')
            info->cmp = mx_compare_size;
        else if (info->cmp != mx_compare_size)
            info->cmp = mx_compare_time;
    }
}

mx_check_name_type(t_info *info, char flag) {
    info->get.name = flag == 'q' ? mx_only_printable : mx_not_printable;
}

mx_check_adds_type(t_info *info, char flag) {

}

mx_check_other_type(t_info *info, char flag) {

}
