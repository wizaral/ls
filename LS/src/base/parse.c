#include "uls.h"

static void parse_file(t_info *info, char *av) {
    DIR *dir = NULL;
    t_stat st;

    if (lstat(av, &st) == -1)
        mx_wrong_arg(info, av);
    else if (MX_ISDIR(st.st_mode) && (dir = opendir(av)) == NULL)
        mx_wrong_arg(info, mx_get_file_name(av));
    else {
        if (dir)
            closedir(dir);
        if (MX_ISREG(st.st_mode)
            || (MX_ISLNK(st.st_mode) && info->write == mx_write_l))
            || (MX_ISDIR(st.st_mode) && info->filedir)
            mx_push_backward(&info->files, &av);
        else
            mx_push_backward(&info->dirs, &av);
    }
}

static bool parse_flag(t_vector *flags, char *av) {
    if (av[0] == '-' && av[1] == '-') {
        if (av[2] != '\0')
            mx_wrong(av[1]);
        return false;
    }

    for (int i = 1; av[i]; ++i)
        MX_EXIST(av[i]) ? mx_push_backward(flags, av + i) : mx_wrong(av[i]);
    return true;
}

void mx_parse(t_info *info, int ac, char **av) {
    static const char *dot = ".";
    t_vector flags = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char),
                        malloc(sizeof(char) * MX_VECTOR_DEFAULT_SIZE)};
    int check = 0;
    int i = 1;

    for (bool flag = true; flag && i < ac && av[i][0] == '-'; ++i)
        flag = parse_flag(&flags, av[i]);
    info->dirs.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    info->files.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    mx_check_flags(info, &flags);
    mx_compress_flags(info, &info->get);
    mx_sort(av + i, ac - i, sizeof(char *),
            info->reverse ? mx_compare_argv_r : mx_compare_argv);

    for (check = i; i < ac; ++i)
        parse_file(info, av[i]);
    if (info->dirs.size == 0 && info->files.size == 0 && check == ac)
        mx_push_backward(info->filedir ? &info->files : &info->dirs, &dot);
    free(flags.arr);
}
