#pragma once
#include "uls.h"

// -rw-r--r--  1        abalabin  4242   2268 Dec 19 15:38 Makefile
// ACCESS      LINKS    LOGIN     GROUP  SIZE   TIME        ent->d_name

typedef struct s_printable {
    char *inode;
    char *blocksize;
    char *access;
    char *links;
    char *user;
    char *grp;
    char *flags;
    char *size;
    char *time;
    char *name;
} t_printable;

typedef struct s_file {
    uint64_t inode;
    // ...
    t_printable fields;
} t_file;

typedef struct s_offset {
    // ...
    size_t lword_size;         // size of longest work in file vector
    int term_width;            // terminal x;
    int curpos;                // current position in x;
} t_offset;

/*
 * st_atimespec;        time of last access
 * st_mtimespec;        time of last data modification
 * st_ctimespec;        time of last status change
 * st_birthtimespec;    time of file creation
 */

typedef enum e_time_type {
    last_access = 0,
    modification = sizeof(struct timespec),
    change = sizeof(struct timespec) * 2,
    creation = sizeof(struct timespec) * 3,
} t_time_type;

typedef struct s_print t_print;
typedef struct s_info t_info;

struct s_info {
    bool output_dst;        // 0 - terminal | 1 - file or other process
    t_file *files;          // pointer to colection of files in next var
    t_vector array;         // struct for manage array of files
    t_time_type time_type;  // data/time type for -[tlgno]
    t_offset off;           // offsets in current directory

    struct s_print {
        void (*inode)(t_info *info);        // print.inode()
        void (*bsize)(t_info *info);        // print.bsize()
        void (*access)(t_info *info);       // print.access()
        void (*user)(t_info *info);         // print.user()
        void (*grp)(t_info *info);          // print.grp()
        void (*flags)(t_info *info);        // print.flags()
        void (*size)(t_info *info);         // print.size()
        void (*time)(t_info *info);         // print.time()
        void (*name)(t_info *info);         // print.name()
        void (*name_add)(t_info *info);     // print.name_add()
        void (*arrow)(t_info *info);        // print.arrow()
        void (*attr)(t_info *info);         // print.attr()
        void (*acl)(t_info *info);          // print.acl()
    } print;

    void (*out)(t_info *info);  // determines type of printing
    void (*read)(t_info *info); // filter of hiden files
    void (*sort)(t_info *info); // sort function for files
};
