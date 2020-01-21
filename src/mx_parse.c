#include "uls.h"

static bool is_flag_exist(char flag) {
    if (mx_get_char_index("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", flag) != -1)
        return true;
    return false;
}

static void mx_parse_dir(char *argum) {
    if (opendir(argum) != NULL)
        return;
    else if (access(argum, F_OK) != -1) {
        // Бахнуть флажок шо эт файл чтобы не пытаться его открыть а просто вывести его доступы допустим в л флаге
        // Или не бахать флажок и сделать такую же проверку уже когда передаем юлсу его
        // И запушить это в лист(или другую структуру данных) файлов(директорий) для вывода
        return;
    }
    else
        // Вывести ошибку шо ебанько и uls: [name]: No such file or directory
        mx_error_nodir(argum);
}

// static void mx_parse_long_flag(char *argum) {
//     char **long_flags_name_arr;

//     for (int i = 0; long_flags_name_arr[i]; ++i) {
//         if (mx_strcmp(argum+2, long_flags_name_arr[i]) == 0)
//          // Заебись отмечаем шо флаг написан
//             return;
//     }
//     mx_error_usage(); // Выкидываем ошибку на эррор юзейджа
//     //mx_free_memory(); // Чистим всё и ливаем из программы
//     exit(0);
// }

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
    // ебашим по всем аргументам
    for (int i = 1; i < argnum; i++) {
        if (!doubleminus && mx_get_char_index(argum[i], '-') != -1 && mx_count_substr(argum[i], "-") == 1 && mx_strlen(argum[i]) != 1)
            mx_parse_flag(argum[i]);
        else if (mx_count_substr(argum[i], "-") == 2)
            doubleminus = true;
        else
            mx_parse_dir(argum[i]);
    }
}
