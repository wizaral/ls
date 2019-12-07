#include "libmx.h"

void mx_fpop_back(t_flist *list) {
    t_flist_node *temp = NULL;

    if (list && list->head) {
        if (list->head != list->tail) {
            temp = list->head;

            while (temp->next->next)
                temp = temp->next;

            free(temp->next);
            temp->next = NULL;

            list->tail = temp;
        }
        else {
            free(list->head);
            list->head = list->tail = NULL;
        }
        --list->size;
    }
}
