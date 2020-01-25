#include "uls.h"

static bool is_flag_exist(char flag) {
    if (mx_get_char_index("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", flag) != -1)
        return true;
    return false;
}

static bool is_flag_valid(bool doubleminus, bool dirprsd, char *argum) {
    if (doubleminus && !dirprsd  && argum[0] != ' '
     && mx_get_char_index(argum, '-') != -1
     && mx_count_substr(argum, "-") == 1
     && mx_strlen(argum) != 1)
        return true;
    return false;
}

static void mx_parse_dir(char *argum) {
    if (opendir(argum) != NULL)
        return;
    else if (access(argum, F_OK) != -1) {
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

static void mx_parse_flag(char *argum) {
    int j = 0;
    // На этапе выбора типа вывода будем брать первый попавшийся флаг из массива и так везде где взаимоисключение
    for (int i = 1; argum[i]; ++i, ++j) {
        if (is_flag_exist(argum[i])) // Проверяем флаг с [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] если есть добавляем
            mx_printstr("Zaebumba±!", 1);
            //flags_arr[j] = argv[i];
        else
            mx_nelegal(argum[i]); // Выводи ошибку причём две illegal option а потом usage_error и ливаем с катки
    }
}

void mx_parse(int argnum, char *argum[]) {
    bool doubleminus = false;
    bool dirparsed = false;
    // ебашим по всем аргументам
    for (int i = 1; i < argnum; i++) {
        if (is_flag_valid(doubleminus, dirparsed, argum[i]))
            mx_parse_flag(argum[i]);
        else if (mx_count_substr(argum[i], "-") == 2)
            if (dirparsed == true)
                mx_parse_dir(argum[i]);
            else
                doubleminus = true;
        else {
            mx_parse_dir(argum[i]);
            dirparsed = true;
        }
    }
}
