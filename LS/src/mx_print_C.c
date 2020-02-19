#include <uls.h>

static int get_tabsin_word(size_t lword) {
    int count = 0;

    for (int ilword = lword; ilword >= 8; ilword -= 8)
        ++count;
    return count;
}

static int get_colnum(t_offset off) {                                 // get number of cols i -C out
    return off.term_width / ((int)off.lword_size +
                             (8 - (int)off.lword_size % 8));
}

static int get_row(size_t vsize, t_offset off) {                      // get number of rows i -C out
    return (vsize % off.colnums) ? vsize / off.colnums + 1
                    : vsize / off.colnums;
}

static void init_data(t_dir *dir) {
    dir->off.colnums = get_colnum(dir->off);
    dir->off.rownums = get_row(dir->array.size, dir->off);
    dir->off.tabs_in_lword = get_tabsin_word(dir->off.lword_size) + 1;
}

void mx_print_c(t_dir *dir) {
    t_file **dt = NULL;
    int tabs_in_cword = 0;

    init_data(dir);                                                              // init data needef for output
    for (size_t i = 0; i < (size_t)dir->off.rownums; ++i) {                      // walk through every row
        for (size_t j = i; j < dir->array.size; j += dir->off.rownums) {         // walk of all elements of i row
            dt = mx_at(&dir->array, j);                                          // take data from vector
            tabs_in_cword = 0;                                                   // init tabs_in_cword;
            if (j < dir->array.size) {                                           // check if we are out of vector or not
                tabs_in_cword = get_tabsin_word(mx_strlen((*dt)->fields.name));  // get tabs in cword (current word)
                mx_printstr((*dt)->fields.name, 1);                              // print name
                if (j + dir->off.rownums != dir->array.size)                     // check if this is last file in row so we dont print tabs
                    print_n_tabs(dir->off.tabs_in_lword - tabs_in_cword ?        // print tabs depending on numb of tabs in lword and cword;
                                 dir->off.tabs_in_lword - tabs_in_cword
                                  : 1);
            }
        }
        mx_printstr("\n", 1);                                                    // go to new row;
    }
}
