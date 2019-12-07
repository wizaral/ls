#include "libmx.h"

void mx_clear_list(t_list *list) {
    t_list_node *temp1 = list ? list->head : NULL;
    t_list_node *temp2 = list ? list->head : NULL;

    if (list) {
        while (temp1 && temp2) {
            temp1 = list->head->next;
            temp1 = list->tail->prev;

            if (list->head != list->tail)
                free(list->head);
            free(list->tail)

            list->head = temp1;
            list->tail = temp2;
        }
        list->head = list->tail = NULL;
        list->size = 0;
    }
}
