#include "uls.h"

// разделить на три вектора: флаги/файлы/папки. ошибки выводить сразу
// вектора для папок и файлов лежат в info, но там память не выделена!!!

static int compare(const void *a, const void *b) {
    return mx_strcmp(a, b);
}

static void read_args(int ac, char **av, t_info *info) {
    // сорт аргов (да, так можно, я гуглил)
    t_vector *flags = mx_create_vector(0, sizeof(char));
    mx_sort(av + 1, ac - 1, sizeof(char *), compare);

    mx_parse(info, ac, av, flags);        // как бы намекаю
    // ВОЗМОЖНО ЛУЧШЕ СНАЧАЛА СЧИТАТЬ ФЛАГИ, А ПОТОМ СОРТИРОВАТЬ ОСТАВШЕЕСЯ
    // тут дележка на два вектора + вывод ошибАк
    mx_delete_vector(flags);
}

// тут сначала выводим файлы
// потом запускаем для папок

static inline void process_args(t_info *info) {
    // структура, в которую по-очереди забивается инфа об открытой папке
    // из argv. (фича: dir->name = av[index])
    t_dir dir = {0};
    info->output_dst = dir.has_bc;

    // фор чёта там
}

int main(int ac, char **av) {
    t_info info = {0};

    if (ac > 1) {
        read_args(ac, av, &info);
        process_args(&info);
    }
    else
        mx_error_usage();

    return info.return_val;
}
