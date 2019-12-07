#include "libmx.h"

void mx_fdelete_list(t_flist **list) {
    if (list && *list) {
        mx_fclear_list(*list);
        free(*list);
        *list = NULL;
    }
}
