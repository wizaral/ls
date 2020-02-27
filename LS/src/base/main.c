#include "uls.h"
#include <stdio.h>

// struct s_info {
    // t_vector arg_dir; // Вектор куда закидываются папки которые явлсяются аргументами
    // t_vector file_vect // Вектор всех файлов в папке для вывода.

//     // Здесь хочу иметь указатель на функцию вывода 
//     // Мб ещё одну структуру сюда в которой будут данные для вывода (макс длина слова и тд)
// } t_info;

// typedef struct s_data {
//     struct stat st;
//     struct dirent *dr;
// } t_data;

// typedef struct s_offsets {
//     size_t longest_word;
//     int wsize;
//     int cnum;
//     int cursize;
// } t_offsets;

// void get_wsize(t_offsets *offsets) {
//     struct ttysize ts;

//     ioctl(1, TIOCGSIZE, &ts);
//     offsets->cnum = ts.ts_cols;
//     offsets->wsize = ts.ts_xxx;
// }

// void get_lword(t_vector *v, t_offsets *off) {
//     off->longest_word = 0;

//     for (size_t i = 0; i < v->size; ++i) {
//         char *name = (*(t_data **)mx_at(v, i))->dr->d_name;
//         if (mx_strlen(name) > off->longest_word)
//             off->longest_word = mx_strlen(name);
//     }
// }

// t_vector *get_files(char *direct) {
//     DIR *dir;
//     t_vector *file_vect = mx_create_vector(0, sizeof(t_data *));
//     t_data *dt = (t_data *)malloc(sizeof(t_data));

//     if ((dir = opendir(direct)) != NULL) {
//         while ((dt->dr = readdir(dir)) != NULL) {
//             lstat(mx_strjoin(mx_strjoin(direct, "/"), dt->dr->d_name), &dt->st);
//             mx_push_backward(file_vect, &dt);
//             dt = (t_data *)malloc(sizeof(t_data));
//         }
//     }
//     return file_vect;
// }

// int cmp(const void *a, const void *b) {
//     return mx_strcmp((*(t_data **)a)->dr->d_name, (*(t_data **)b)->dr->d_name) > 0;
// }

// int main(int argc, char **argv) {
//     if (argc) {
//         t_vector *v = get_files(argv[1]);
//         t_offsets *offsets = malloc(sizeof(t_offsets));
//         get_wsize(offsets);
//         get_lword(v, offsets);
//         offsets->cursize = 0;

//         for (size_t i = 0; i < v->size; ++i) {
//             t_data **dt = mx_at(v, i);

//             printf("%s", (*dt)->dr->d_name);
//         }
//     }
// }

// ========================================================================= //

// разделить на три вектора: флаги/файлы/папки. ошибки выводить сразу
// вектора для папок и файлов лежат в info, но там память не выделена!!!

static void read_args(int ac, char **av, t_info *info) {
    // сорт аргов (да, так можно, я гуглил)
    t_vector *flags = mx_create_vector(0, sizeof(char));
    mx_sort(av + 1, ac - 1, sizeof(char *), mx_strcmp);

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
    t_dir dir = {};

    // фор чёта там
}

int main(int ac, char **av) {
    if (ac > 1) {
        t_info info = {};

        read_args(ac, av, &info);
        process_args(&info);
    }
    else
        mx_error_usage();
}
