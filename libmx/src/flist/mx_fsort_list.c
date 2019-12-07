#include "libmx.h"

t_flist *mx_fsort_list(t_flist *list, int (*cmp)(const void *, const void *)) {
    int swaps = 0;

    for (t_flist_node *node1 = list; node1 && cmp; node1 = node1->next) {
        for (t_flist_node *node2 = list; node2->next; node2 = node2->next)
            if (cmp(node2->data, node2->next->data) > 0) {
                mx_swap(&node2->data, &node2->next->data, sizeof(void *));
                ++swaps;
            }
        if (swaps == 0)
            break;
    }
    return list;
}
