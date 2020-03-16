#include "uls.h"

static inline void init_getters(t_get *get, bool dst) {
    get->access = mx_dummy;
    get->bsize = mx_dummy;
    get->grp = mx_dummy;
    get->inode = mx_dummy;
    get->links = mx_dummy;
    get->name = dst ? mx_not_printable : mx_only_printable;
    get->size = mx_dummy;
    get->suffix = mx_dummy;
    get->time = mx_dummy;
    get->user = mx_dummy;
}

static inline void init_info(t_info *info) {
    info->output_dst = !isatty(1);
    info->write = info->output_dst ? mx_write_1 : mx_write_C;
    info->read = mx_standart;
    info->cmp = mx_compare_ascii;
    info->print_total = mx_nototal;
    info->print_name = mx_nocolor;
    info->recursion = mx_uls;
    info->time_type = modification;
    info->return_val = 0;
    info->reverse = 0;
    info->filedir = 0;
    info->dirs.cap = MX_VECTOR_DEFAULT_SIZE;
    info->dirs.bytes = sizeof(t_file);
    info->dirs.size = 0;
    info->files.cap = MX_VECTOR_DEFAULT_SIZE;
    info->files.bytes = sizeof(char *);
    info->files.size = 0;
    init_getters(&info->get, info->output_dst);
    errno = 0;
}

int main(int ac, char **av) {
    t_info info = {0};

    init_info(&info);
    mx_parse(&info, ac, av);
    mx_process_args(&info);
    return info.return_val;
}
