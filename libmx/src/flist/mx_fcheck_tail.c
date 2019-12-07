#include "libmx.h"

t_flist_node *mx_fcheck_tail(t_flist *list) {
    t_flist_node *tail = list ? list->head : NULL;

    for (; tail && tail->next; tail = tail->next);
    return list ? list->tail = tail : NULL;
}
