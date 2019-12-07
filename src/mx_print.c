#include "uls.h"

void mx_print_w_flags(t_file *file_list) {
    int count = 0;

    for (t_file *temp = file_list; temp; temp = temp->next) {
        if (mx_strncmp(temp->data->ent->d_name, ".", 1) != 0) {
            if (count != 4) {
                if (count > 0)
                    printf("\t%s", temp->data->ent->d_name);
                else if (count == 0)
                    printf( "%s\t", temp->data->ent->d_name);
                count++;
            }
            else {
                printf("\t%s\n", temp->data->ent->d_name);
                count = 0;
            }
        }
    }
}
