#include "uls.h"

// в планах сделать в либе:
// бинарное дерево
// двухсвязный список
// 
// мержсорт (не факт) (нужен вектор)
// бинарный поиск (нужен вектор)
// 
// побольше дефайнов для длинных тИпов const unsigned long long и т.п.
// немного макросов для операций min max и т.п. (аудитор ахтунг!)
// сделать БОЛЬ_шинство функций более универсальными (смари принт секцию)

// ========================================================================= //

int main(int argc, char **argv) {
    if (argc)
        mx_uls(argv[1]);
    return 0;
}
