#include "uls.h"

// тут сначала выводим файлы
// потом запускаем для папок

// static inline void process_args(t_info *info) {
//     // структура, в которую по-очереди забивается инфа об открытой папке
//     // из argv. (фича: dir->name = av[index])
//     t_dir dir = {0};
//     info->output_dst = dir.has_bc;

//     // фор чёта там
// }

static inline void init_getters(t_get *get, bool dst) {
    get->access = mx_dummy;
    get->acl = mx_dummy;
    get->attr = mx_dummy;
    get->bsize = mx_dummy;
    get->flags = mx_dummy;
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
    info->read = mx_standart;
    info->cmp = mx_compare_ascii;
    info->time_type = modification;
    info->output_dst = !isatty(1);
    info->write = info->output_dst ? mx_write_1 : mx_write_C;
    info->print_name = mx_nocolor;
    info->recursion = mx_uls;
    info->directories.cap = MX_VECTOR_DEFAULT_SIZE;
    info->directories.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    info->directories.bytes = sizeof(char *);
    info->directories.size = 0;
    info->files.cap = MX_VECTOR_DEFAULT_SIZE;
    info->files.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    info->files.bytes = sizeof(char *);
    info->files.size = 0;
    init_getters(&info->get, info->output_dst);
    errno = 0;
}

int main(int ac, char **av) {
    t_info info = {0};

    if (ac > 1) {
        init_info(&info);
        mx_parse(&info, ac, av);
        // process_args(&info);
    }
    else
        mx_error_usage();

    return info.return_val;
}
