#include <uls.h>

static int get_tabsin_word(size_t lword) {
    int count = 0;

    for (int ilword = lword; ilword >= 8; ilword -= 8)
        ++count;
    return count;
}

static void get_colnum(t_offset *off) {                                 // get number of cols i -C out
    off->colnums = off->term_width / ((int)off->lword_size +
                                     (8 - (int)off->lword_size % 8));
}

static void get_row(size_t vsize, t_offset *off) {                      // get number of rows i -C out
    off->rownums = (vsize % off->colnums) ? vsize / off->colnums + 1
                    : vsize / off->colnums;
}

static void init_data(t_info *info) {
    get_colnum(info->off);
    get_row(info->array->size, info->off);
    info->off->tabs_in_lword = get_tabsin_word(info->off->lword_size) + 1;
}

void mx_print_c(t_info *info) {
    t_file **dt = NULL;
    int tabs_in_cword = 0;

    init_data(info);                                                             // init data needef for output
    for (size_t i = 0; i < (size_t)info->off->rownums; ++i) {                    // walk through every row
        for (size_t j = i; j < info->array->size; j += info->off->rownums) {     // walk of all elements of i row
            dt = mx_at(info->array, j);                                          // take data from vector
            tabs_in_cword = 0;                                                   // init tabs_in_cword;
            if (j < info->array->size) {                                         // check if we are out of vector or not
                tabs_in_cword = get_tabsin_word(mx_strlen((*dt)->fields.name));  // get tabs in cword (current word)
                mx_printstr((*dt)->fields.name, 1);                              // print name
                if (j + info->off->rownums != info->array->size)                 // check if this is last file in row so we dont print tabs
                    print_n_tabs(info->off->tabs_in_lword - tabs_in_cword ?      // print tabs depending on numb of tabs in lword and cword;
                                 info->off->tabs_in_lword - tabs_in_cword
                                  : 1);
            }
        }
        mx_printstr("\n", 1);                                                    // go to new row;
    }
}