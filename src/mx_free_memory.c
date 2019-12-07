#include "uls.h"

void mx_clear_file_list(t_file *list) {
    while (list) {
        mx_pop_file_list_back(&list);
    }
}
