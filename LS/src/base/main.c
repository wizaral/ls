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

int main(int ac, char **av) {
    t_info info = {0};

    if (ac > 1 && av) {
        mx_parse(&info, ac, av);
        // process_args(&info);
    }
    else
        mx_error_usage();

    return info.return_val;
}
