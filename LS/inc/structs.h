#pragma once
#include "uls.h"

// -rw-r--r--  1        abalabin  4242   2268 Dec 19 15:38 Makefile
// ACCESS      LINKS    LOGIN     GROUP  SIZE   TIME        ent->d_name

typedef struct s_file {
    uint64_t inode;
    uint64_t blocksize;
    char *access;
    uint64_t links;
    char *user;
    char *grp;
    char *flags;
    char *size;
    char *time;
    char *name;
} t_file;

/*
 * st_atimespec;        time of last access
 * st_mtimespec;        time of last data modification
 * st_ctimespec;        time of last status change
 * st_birthtimespec;    time of file creation
 */

typedef enum e_time_type {
    last_access = 0,
    modification = 0,//sizeof(struct timespec),
    change = 0,//sizeof(struct timespec) * 2,
    creation = 0,//sizeof(struct timespec) * 3,
} t_time_type;

typedef struct s_print t_print;
typedef struct s_info t_info;

struct s_info {
    bool output_dst;        // 0 - terminal | 1 - file
    t_file *files;          // pointer to colection of files in next var
    t_vector array;         // struct for manage array of files
    t_time_type time_type;  // data/time type for -[tlgno]

    struct s_print {
        void (*inode)(t_info *info);        // print.inode
        void (*bsize)(t_info *info);        // print.bsize
        void (*access)(t_info *info);       // print.access
        void (*user)(t_info *info);         // print.user
        void (*grp)(t_info *info);          // print.grp
        void (*flags)(t_info *info);        // print.flags
        void (*size)(t_info *info);         // print.size
        void (*time)(t_info *info);         // print.time
        void (*name)(t_info *info);         // print.name
        void (*name_add)(t_info *info);     // print.name_add
        void (*arrow)(t_info *info);        // print.arrow
    } print;

    void (*out)(t_info *info);  // determines type of printing
    void (*sort)(t_info *info); // sort function for files
};
