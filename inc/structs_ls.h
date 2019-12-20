#ifndef STRUCTS_LS_H
#define STRUCTS_LS_H

// -rw-r--r--  1        abalabin  4242   2268 Dec 19 15:38 Makefile
// ACCESS      LINKS    LOGIN     GROUP  SIZE   TIME        ent->d.name
// This how -l flag standart works;

typedef struct s_data {
    struct dirent *ent;
    char *path;

//  Fields for -l flag
    char *access;
    char *links;
    char *login;
    char *grp;
    char *size;
    char *time;
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

    // Fields for -lflag print
    t_ull laccess;
    t_ull llinks;
    t_ull llogin;
    t_ull lgrp;
    t_ull lsize;

    t_ull total;
} t_info;

#endif
