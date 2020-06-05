#include "uls.h"

static void parse_file(t_info *info, char *av) {
    t_stat st;

    if (lstat(av, &st) == -1)
        mx_wrong_argv(info, av);
    else if ((!MX_ISDIR(st.st_mode) && !MX_ISLNK(st.st_mode))
        || (MX_ISLNK(st.st_mode) && info->write == mx_write_l)
        || (MX_ISLNK(st.st_mode) && info->get.suffix != mx_dummy)
        || (MX_ISDIR(st.st_mode) && info->filedir)) {
        mx_push_backward(&info->files, &av);
    }
    else {
        t_file file = {{.name = av}, {0}, {0}, st.st_size, 0};

        file.time = *(&st.st_atimespec + info->time_type);
        mx_push_backward(&info->dirs, &file);
    }
}

static bool parse_flag(t_vector *flags, char *av) {
    if (av[0] == '-' && av[1] == '-') {
        if (av[2] != '\0') {
            mx_wrong_flag(av[1]);
        }
        return false;
    }
    if (av[0] == '-' && av[1] == '\0') {
        mx_wrong_flag(av[1]);
    }

    for (int i = 1; av[i]; ++i) {
        if (MX_EXIST(av[i])) {
            mx_push_backward(flags, av + i);
        }
        else {
            mx_wrong_flag(av[i]);
        }
    }
    return true;
}

static inline void add_default_dir(t_info *info) {
    static char *dot = ".";

    if (info->filedir) {
        mx_push_backward(&info->files, &dot);
    }
    else {
        t_file file = {{.name = dot}, {0}, {0}, 0, 0};

        mx_push_backward(&info->dirs, &file);
    }
}

void mx_parse(t_info *info, int ac, char **av) {
    t_vector flags = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char),
                        malloc(sizeof(char) * MX_VECTOR_DEFAULT_SIZE)};
    int check = 0;
    int i = 1;

    for (bool flag = true; flag && i < ac && av[i][0] == '-'; ++i)
        flag = parse_flag(&flags, av[i]);
    info->dirs.arr = malloc(sizeof(t_file) * MX_VECTOR_DEFAULT_SIZE);
    info->files.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    mx_check_flags(info, &flags);
    mx_compress_flags(info, &info->get);

    if (info->cmp)
        mx_sort(av + i, ac - i, sizeof(char *), mx_compare_argv);
    for (check = i; i < ac; ++i)
        parse_file(info, av[i]);
    mx_sort(info->dirs.arr, info->dirs.size, info->dirs.bytes, info->cmp);
    if (info->dirs.size == 0 && info->files.size == 0 && check == ac)
        add_default_dir(info);
    free(flags.arr);
}
