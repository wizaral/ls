#include "libmx.h"

t_flist_node *mx_fcheck_tail(t_flist *list) {
    t_flist_node *node = list ? list->head : NULL;

    for (; node && node->next; node = tail->next);
    return list ? list->tail = node : NULL;
}
