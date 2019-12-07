#include "uls.h"

int mx_file_list_size(t_file *list) {
    int size = 0;

    if (list)
        for (t_file *temp = list; temp; temp = temp->next, size++);

    return size;
}

t_file *mx_create_file_node(struct dirent *ent) {
    t_file *node = (t_file *)malloc(sizeof(t_file));

    if (node) {
        node->data = (t_data *)malloc(sizeof(t_data));
        node->data->ent = ent;
        stat(ent->d_name, node->data->st);
        node->next = NULL;
    }
    return node;
}

void mx_push_file_back(t_file **file_list, struct dirent *ent) {
    t_file *temp = NULL;

    if (*file_list == NULL)
        *file_list = mx_create_file_node(ent);
    else {
        temp = *file_list;
        for (; temp->next != NULL; temp = temp->next) {};
        temp->next = mx_create_file_node(ent);
    }
}


void mx_push_file_front(t_file **file_list, struct dirent *ent) {
    t_file *file = mx_create_file_node(ent);

    if (file_list && file != NULL) {
        file->next = *file_list;
        *file_list = file;
    }
    else
        *file_list = file;
}

void mx_pop_file_list_back(t_file **head) {
    t_file *temp = NULL;

    if (head && *head && (*head)->next) {
        temp = *head;
        while (temp->next->next)
            temp = temp->next;
        free(temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
    else if (head && *head) {
        free((*head)->data);
        free(*head);
        *head = NULL;
    }
}
