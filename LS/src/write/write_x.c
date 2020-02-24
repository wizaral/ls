#include "uls.h"

// ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД


// ПОЛУЧИТЬ КОЛИЧЕСТВО ТАБОВ В САМОМ ДЛИННОМ СЛОВЕ
static int get_tabsin_word(size_t lword) {
    int count = 0;

    for (int ilword = lword; ilword >= 8; ilword -= 8)
        ++count;
    return count;
}

// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_tabs(int tabs) {
    for (int i = 0; i < tabs; ++i)
        mx_printstr("\t", 1);
}

static void print_tabs(size_t lword, size_t cword, t_offset *of) {
    int tabs_inlword = get_tabsin_word(lword) + 1; // убрать в t_offsets надо будет и вызывать один раз
    int tabs_cword = get_tabsin_word(cword);

    if (of->colnums >= of->curpos_in_term + tabs_inlword * 16) {
        of->curpos_in_term += tabs_inlword * 8;
        print_n_tabs(lword - cword ? tabs_inlword - tabs_cword : 1);
    }
    else {
        mx_print_str("\n", 1);
        of->curpos_in_term = 0;
    }
}

void print_x(t_dir *dir) {
    t_file **dt = NULL;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_printstr((*dt)->drnt->d_name, 1);
        if (i + 1 != dir->array.size)
            print_tabs(dir->off.lname_len, mx_strlen((*dt)->drnt->d_name), &dir->off);
    }
}
