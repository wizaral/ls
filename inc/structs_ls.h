#ifndef STRUCTS_LS_H
#define STRUCTS_LS_H

typedef struct s_data {
    struct dirent *ent;
    struct stat *st;
} t_data;

typedef struct s_file {
    t_data *data;
    struct s_file *next;
} t_file;

#endif
