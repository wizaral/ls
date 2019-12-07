#include "libmx.h"

void mx_fclear_list(t_flist *list) {
    t_flist_node *temp = list ? list->head : NULL;

    if (list) {
        while (temp) {
            temp = list->head->next;
            free(list->head);
            list->head = temp;
            --list->size;
        }
        list->head = list->tail = NULL;
    }
}
