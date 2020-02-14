#include <uls.h>

// ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД


// ПОЛУЧИТЬ КОЛИЧЕСТВО ТАБОВ В САМОМ ДЛИННОМ СЛОВЕ
static int get_tabsin_word(size_t lword) {
    int count = 0;
    int ilword = (int)lword;

    while (ilword >= 8) {
        count++;
        ilword -= 8;
    }
    return count;
}
// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_tabs(int tabs) {
    for (int i = 0; i < tabs; ++i)
        printf("\t");
}

static void print_tabs(size_t lword, size_t cword, t_offsets *of) {
    int tabs_inlword = get_tabsin_word(lword) + 1; // убрать в t_offsets надо будет и вызывать один раз
    int tabs_cword = get_tabsin_word(cword);

    if (of->cnum >= of->cursize + tabs_inlword * 16) {
        of->cursize += tabs_inlword * 8;
        if (lword - cword != 0)
            print_n_tabs(tabs_inlword - tabs_cword);
        else 
            print_n_tabs(1);
    }
    else {
        printf("\n");
        of->cursize = 0;
    }
}

void mx_print_x(t_info *info) {
    for (size_t i = 0; i < info->array->size; ++i) {
        t_file **dt = mx_at(info->array, i);
        
        printf("%s", (*dt)->name);
        if (i + 1 != info->array->size)
            print_spaces_tolword(offsets->longest_word, mx_strlen((*dt)->name), offsets);
    }
}
