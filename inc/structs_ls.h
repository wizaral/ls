#ifndef STRUCTS_LS_H
#define STRUCTS_LS_H

typedef struct s_data {
    struct dirent *ent;
    struct stat *st;
    struct lstat *lst;
    char *access;
} t_data;

typedef struct s_file {
    t_data *data;
    struct s_file *next;
} t_file;

typedef struct s_info {
    t_ull max_len;
    t_ull cols;
    t_ull lines;
    t_ull num_of_sub;
} t_info;

#endif
