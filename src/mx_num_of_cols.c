#include "uls.h"

int mx_num_of_cols(t_file *list) {
    struct winsize w;
    int max_len = 0;
    int cols = 0;
    int lines = 0;

    for (t_file *tmp = list; tmp; tmp = tmp->next)
        if (max_len < mx_strlen(tmp->data))
            max_len = mx_strlen(tmp->data);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    cols = (w.ws_col / ((8 - (max_len % 8)) + max_len));
    lines = list_size(list) / cols;
        if (lines == 0 || ((list_size(list) % cols) != 0))
            lines++;
    return lines;
}
