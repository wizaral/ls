#include "uls.h"

// int mx_num_of_cols(t_file *list, t_info info) {
//     struct winsize w;

//     for (t_file *tmp = list; tmp; tmp = tmp->next)
//         if (info.max_len < mx_strlen(tmp->data))
//             info.max_len = mx_strlen(tmp->data);
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//     info.cols = (w.ws_col / ((8 - (info.max_len % 8)) + info.max_len));
//     info.lines = list_size(list) / info.cols;
//         if (info.lines == 0 || ((list_size(list) % cols) != 0))
//             info.lines++;
//     return info.lines;
// }

void mx_num_of_cols(t_vector *file_vect, t_info *info) {
    struct winsize w;
    t_data *data = NULL;

    info->max_len = 0;
    info->cols = 0;
    info->lines = 0;
    info->num_of_sub = file_vect->size;

    for (size_t i = 0; i < file_vect->size; ++i) {
        data = mx_at(file_vect, i);
        if (info->max_len < mx_strlen(data->ent->d_name))
            info->max_len = mx_strlen(data->ent->d_name);
    }
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    info->cols = (w.ws_col / ((8 - (info->max_len % 8)) + info->max_len));
    info->lines = file_vect->size / info->cols;
        if (info->lines == 0 || ((file_vect->size % info->cols) != 0))
            info->lines++;
}
