#include "libmx.h"

void mx_fpush_index(t_flist *list, void *data, t_ll index) {
    t_flist_node *prev_node = list ? list->head : NULL;
    t_flist_node *new_node = NULL;

    if (list) {
        if (index <= 0)
            mx_fpush_front(list, data);
        else if (index >= list->size)
            mx_fpush_back(list, data);
        else {
            for (t_ll pos = 0; ++pos < index; prev_node = prev_node->next);
            if ((new_node = mx_fcreate_node(data, prev_node->next)) != NULL)
                prev_node->next = new_node;
        }
    }
}
