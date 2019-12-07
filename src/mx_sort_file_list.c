#include "uls.h"

static void list_swap(t_data **data1, t_data **data2) {
    t_data *temp = *data1;

    *data1 = *data2;
    *data2 = temp;
}

static bool cmp(t_file *lst1, t_file *lst2) {
    if (lst1 && lst2) {

    char *name1 = lst1->data->ent->d_name;
    char *name2 = lst2->data->ent->d_name;

    if (mx_strcmp(name1, name2) > 0)
        return true;
    }
    return false;
}

void mx_sort_file_list(t_file *lst) {
    if (lst) {
        for (t_file *node1 = lst; node1; node1 = node1->next)
            for (t_file *node2 = lst; node2->next; node2 = node2->next)
                if (cmp(node2, node2->next))
                    list_swap(&node2->data, &node2->next->data);
    }
}
