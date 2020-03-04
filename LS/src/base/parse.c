#include "uls.h"

static inline char *get_file_name(char *av) {
    for (char *temp = mx_strchr(av, '/'); temp; temp = mx_strchr(av, '/'))
        av = temp + 1;
    return av;
}

static void parse_file(t_info *info, char *av) {
    DIR *dir = NULL;
    t_stat st;

    if (lstat(av, &st) == -1) {
        info->return_val = 1;
        mx_printstr("ls: ", 2);
        perror(av);
    }
    else if ((dir = opendir(av)) == NULL) {
        info->return_val = 1;
        mx_printstr("ls: ", 2);
        perror(get_file_name(av));
    }
    else {
        closedir(dir);
        if (MX_ISREG(st.st_mode))
            mx_push_backward(&info->files, &av);
        else
            mx_push_backward(&info->directories, &av);
    }
}

static inline void check_doubleminus(char *av) {
    if (av[2])
        mx_nelegal(av[1]);
}

static bool parse_flag(t_vector *flags, char *av) {
    if (av[0] == '-' && av[1] == '-') {
        check_doubleminus(av);
        return false;
    }

    for (int i = 1; av[i]; ++i) {
        if (MX_EXIST(av[i]))
            mx_push_backward(flags, av + i);
        else
            mx_nelegal(av[i]);
    }
    return true;
}

void mx_parse(t_info *info, int ac, char **av) {
    t_vector flags = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char),
                      malloc(sizeof(char) * MX_VECTOR_DEFAULT_SIZE)};
    int i = 1;

    for (bool flag = true; flag && i < ac && av[i][0] == '-'; ++i)
        flag = parse_flag(&flags, av[i]);

    info->directories.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);
    info->files.arr = malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE);

    for (; i < ac; ++i)
        parse_file(info, av[i]);

    mx_check_flags(info, &flags);
    mx_minimize_flags(info, &info->get);
    free(flags.arr);
}
