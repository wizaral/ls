#include "uls.h"

static inline bool is_flag_exist(char flag) {
    return mx_strchr(MX_FLAGS, flag) != NULL;
}

static char *get_file_name(char *av) {
    char *str = av;

    for (char *temp = mx_strchr(str, '/'); temp; temp = mx_strchr(str, '/'))
        str = temp + 1;
    return str;
}

static void mx_parse_dir(char *av) {
    if (opendir(av) != NULL)
        return;
    else if (access(av, F_OK) != -1) {
        if (access(av, R_OK) != 0) {
            mx_printstr("uls: ", 2);
            mx_printstr(get_file_name(av), 2);
            mx_printstr(": Permission denied\n", 2);
        }
        // Бахнуть флажок шо эт файл чтобы не пытаться его открыть а просто вывести его доступы допустим в л флаге
        // Или не бахать флажок и сделать такую же проверку уже когда передаем юлсу его
        // Не кикать из вектора arg_dir эта папка вполе себе папка
        return;
    }
    else
        // Вывести ошибку шо ебанько и uls: [name]: No such file or directory
        // И кикнуть нахер с вектора arg_dir это неправильная папка и её открывать потом ненадо
        mx_error_nodir(av);
}

static bool check_doubleminus(char *av) {
    if (mx_strlen(av) == 2)
        return true;
    if (av[1] == '-')
        mx_nelegal(av[1]);
    return false;
}

static void mx_parse_flag(char *av, bool *dirparsed) {
    if (av[0] != '-') {
        mx_parse_dir(av);
        *dirparsed = true;
        return;
    }
    if (mx_count_substr(av, "-") == 2) {
        *dirparsed = check_doubleminus(av);
        return;
    }

    for (int i = 1; av[i]; ++i) {
        if (is_flag_exist(av[i])) // Проверяем флаг с [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] если есть добавляем
            mx_printstr("Zaebumba!\n", 2);
        else
            mx_nelegal(av[i]); // Выводи ошибку причём две illegal option а потом usage_error и ливаем с катки
    }
}

void mx_parse(int ac, char *av[]) {
    bool dirparsed = false;

    for (int i = 1; i < ac; ++i) {
        if (dirparsed == false && mx_strchr(av[i], '-'))
            mx_parse_flag(av[i], &dirparsed);
        else
            mx_parse_dir(av[i]);
    }
}
