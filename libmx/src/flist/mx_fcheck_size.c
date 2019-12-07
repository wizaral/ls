#include "libmx.h"

t_ll mx_fcheck_size(t_flist *list) {
    t_ll size = 0;

    for (t_flist_node *node = list ? list->head : NULL; node; ++size)
        node = node->next;
    return list ? list->size = size : -1;
}
