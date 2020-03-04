#include "uls.h"

// тут ещё всё сырое

// static void mx_hr_write_number(char *size, int64_t st_size) {
//     for (int i = 2; i > -1; --i) {
//         if (st_size > 0) {
//             size[i] = st_size % 10 + 48;
//             st_size /= 10;
//         }
//         else
//             size[i] = ' ';
//     }
// }

// static int mx_hr_get_pow(int64_t st_size) {
//     int pow = 0;

//     for (; st_size > 999; st_size /= 1024)
//         pow += 10;
//     return pow;
// }

// static inline int round_num(double num) {
//     return (((int64_t)(num * 10)) / 10) + ((((int64_t)(num * 10)) % 10) > 4);
// }

// static inline void add_pref(char *size, int pow) {
//     static const char *exp = "  \
//         K         M         G         T         P";

//     *size = exp[pow];
// }

// static void size_more_thous(int64_t num, double g, int pow, char *size) {
//     if (g >= 9.95) {
//         num = round_num(g);
//         if (num < 999)
//             mx_hr_write_number(size, num);
//         else {
//             num = round_num(g * 10);
//             pow += 10;
//             size[0] = num / 10 + 48;
//             size[1] = '.';
//             size[2] = num % 10 + 48;
//         }
//     }
//     else {
//         num = round_num(g * 10);
//         size[0] = num / 10 + 48;
//         size[1] = '.';
//         size[2] = num % 10 + 48;
//     }
//     add_pref(size + 3, pow);
// }

// static void size_less_thousand(int64_t num, char *size) {
//     if (num == 0)
//         mx_strcpy(size, "  0");
//     else
//         mx_hr_write_number(size, num);
//     size[3] = 'B';
// }

void mx_size_h(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    // char *size = mx_strnew(4);
    // int pow = 0;

    // if (file->size < 1000)
    //     size_less_thousand(file->size, size);
    // else {
    //     pow = mx_hr_get_pow(file->size);
    //     size_more_thous(file->size, file->size / mx_pow(2, pow), pow, size);
    // }
    // return size;
    ++info;
    ++dir;
    ++file;
    ++st;
}

void mx_size_b(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    ++info;
    ++dir;
    ++file;
    ++st;
}
