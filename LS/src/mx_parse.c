#include "uls.h"

static bool is_flag_exist(char flag) {
    if (mx_get_char_index("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", flag) != -1)
        return true;
    return false;
}

static char *get_file_name(char *argum) {
    char *str = argum;

    while (mx_get_char_index(str, '/') != -1) {
        str += mx_get_char_index(str, '/') + 1;
    }

    return str;
}

static void mx_parse_dir(char *argum) {
    if (opendir(argum) != NULL)
        return;
    else if (access(argum, F_OK) != -1) {
        if (access(argum, R_OK) != 0) {
            printf("uls: %s: Permission denied\n", get_file_name(argum));
        }
        // Бахнуть флажок шо эт файл чтобы не пытаться его открыть а просто вывести его доступы допустим в л флаге
        // Или не бахать флажок и сделать такую же проверку уже когда передаем юлсу его
        // Не кикать из вектора arg_dir эта папка вполе себе папка
        return;
    }
    else
        // Вывести ошибку шо ебанько и uls: [name]: No such file or directory
        // И кикнуть нахер с вектора arg_dir это неправильная папка и её открывать потом ненадо
        mx_error_nodir(argum);
}


static bool check_doubleminus(char *argum) {
    if (mx_strlen(argum) == 2) {
        return true;
    }
    if (argum[1] == '-')
        mx_nelegal(argum[1]);
    return false;
}

static void mx_parse_flag(char *argum, bool *dirparsed) {
    int j = 0;

    if (argum[0] != '-') {
        mx_parse_dir(argum);
        *dirparsed = true;
        return;
    }
    if (mx_count_substr(argum, "-") == 2) {
        *dirparsed = check_doubleminus(argum);
        return;
    }

    for (int i = 1; argum[i]; ++i, ++j) {
        if (is_flag_exist(argum[i])) // Проверяем флаг с [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] если есть добавляем
            mx_printstr("Zaebumba±!", 1);
            //flags_arr[j] = argv[i];
        else
            mx_nelegal(argum[i]); // Выводи ошибку причём две illegal option а потом usage_error и ливаем с катки
    }
}

void mx_parse(int argnum, char *argum[]) {
    bool dirparsed = false;

    for (int i = 1; i < argnum; ++i) {
        if (!dirparsed && mx_get_char_index(argum[i], '-') != -1)
            mx_parse_flag(argum[i], &dirparsed);
        else {
            mx_parse_dir(argum[i]);
        }
    }
}
