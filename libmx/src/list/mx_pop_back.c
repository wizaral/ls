#include "libmx.h"

void mx_pop_back(t_list *list) {
    t_list_node *temp = NULL;

    if (list && list->head) {
        if (list->head != list->tail) {
            temp = list->tail->prev;
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
