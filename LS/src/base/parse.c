#include "uls.h"

static inline char *get_file_name(char *av) {
    for (char *temp = mx_strchr(av, '/'); temp; temp = mx_strchr(av, '/'))
        av = temp + 1;
    return av;
}

static void parse_file(t_info *info, char *av) {
    DIR *dir = NULL;
    t_stat st;

    if (lstat(av, &st) == -1 && (info->return_val = 1)) {
        mx_printstrlen("uls: ", 5, 2);
        perror(av);
    }
    else if (MX_ISDIR(st.st_mode) && (dir = opendir(av)) == NULL) {
        info->return_val = 1;
        mx_printstrlen("uls: ", 5, 2);
        perror(get_file_name(av));
    }
    else {
        dir ? closedir(dir) : 0;
        if (MX_ISREG(st.st_mode)
            || (MX_ISLNK(st.st_mode) && info->write == mx_write_l))
            mx_push_backward(&info->files, &av);
        else
            mx_push_backward(&info->directories, &av);
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
    t_vector flags = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char), malloc(sizeof(char) * MX_VECTOR_DEFAULT_SIZE)};
    int check = 0;
    int i = 1;

    for (bool flag = true; flag && i < ac && av[i][0] == '-'; ++i)
        flag = parse_flag(&flags, av[i]);

    info->directories.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    info->files.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    mx_check_flags(info, &flags);
    mx_compress_flags(info, &info->get);

    // test this !!
    // mx_sort(av + i, ac - i, sizeof(char *), info->reverse ? mx_compare_argv_r : mx_compare_argv);

    for (check = i; i < ac; ++i)
        parse_file(info, av[i]);
    if (info->directories.size == 0 && info->files.size == 0 && check == ac)
        mx_push_backward(&info->directories, &dot);
    free(flags.arr);
}
