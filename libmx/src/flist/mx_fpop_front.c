#include "libmx.h"

void mx_fpop_front(t_flist *list) {
    t_flist_node *temp = NULL;

    if (list && list->head) {
        temp = list->head;
        list->head = list->head->next;

        --list->size;
        free(temp);

        if (list->head == NULL)
            list->tail = NULL;
    }
}
