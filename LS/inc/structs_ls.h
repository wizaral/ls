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
    uint64_t max_len;
    int64_t cols;
    int64_t lines;
    int64_t num_of_sub;

    // Fields for -lflag print
    int64_t laccess;
    int64_t llinks;
    int64_t llogin;
    int64_t lgrp;
    int64_t lsize;

    int64_t total;
} t_info;

#endif
