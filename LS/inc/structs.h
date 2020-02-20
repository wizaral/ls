#pragma once
#include "uls.h"

// -rw-r--r--  1        abalabin  4242   2268 Dec 19 15:38 Makefile
// ACCESS      LINKS    LOGIN     GROUP  SIZE   TIME        ent->d_name

typedef struct s_lengths {
    uint8_t inode;
    uint8_t bsize;
    uint8_t links;
    uint8_t user;
    uint8_t grp;
    uint8_t flags;
    uint8_t size;
} t_lengths;

typedef struct s_printable {
    char *inode;
    char *bsize;
    char *access;
    char *links;
    char *user;
    char *grp;
    char *flags;
    char *size;
    char *time;
    char *arrow;
    char *attr;
    char *acl;
    t_lengths lengths;
} t_printable;

typedef struct s_file {
    struct dirent *drnt;
    struct timespec time;
    // ...
    t_printable fields;
} t_file;

typedef struct s_offset {
    // ...
    size_t lword_size;      // size of longest work in file vectors
    int tabs_in_lword;      // tabs in lword;
    int colnums;            // number of columns in C out
    int rownums;            // number of rows in C out
    int term_width;         // terminal x;
    int curpos;             // current position in x;
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

typedef struct s_info t_info;
typedef struct s_dir t_dir;

typedef struct s_get {
    void (*inode)(t_dir *dir, size_t file);     // get.inode()
    void (*bsize)(t_dir *dir, size_t file);     // get.bsize()
    void (*access)(t_dir *dir, size_t file);    // get.access()
    void (*links)(t_dir *dir, size_t file);     // get.links()
    void (*user)(t_dir *dir, size_t file);      // get.user()
    void (*grp)(t_dir *dir, size_t file);       // get.grp()
    void (*flags)(t_dir *dir, size_t file);     // get.flags()
    void (*size)(t_dir *dir, size_t file);      // get.size()
    void (*time)(t_dir *dir, size_t file);      // get.time()
    void (*name)(t_dir *dir, size_t file);      // get.name()
    void (*suffix)(t_dir *dir, size_t file);    // get.suffix()
    void (*arrow)(t_dir *dir, size_t file);     // get.arrow()
    void (*attr)(t_dir *dir, size_t file);      // get.attr()
    void (*acl)(t_dir *dir, size_t file);       // get.acl()
} t_get;

typedef struct s_print {
    void (*inode)(t_dir *dir, size_t file);     // print.inode()
    void (*bsize)(t_dir *dir, size_t file);     // print.bsize()
    void (*access)(t_dir *dir, size_t file);    // print.access()
    void (*links)(t_dir *dir, size_t file);     // print.links()
    void (*user)(t_dir *dir, size_t file);      // print.user()
    void (*grp)(t_dir *dir, size_t file);       // print.grp()
    void (*flags)(t_dir *dir, size_t file);     // print.flags()
    void (*size)(t_dir *dir, size_t file);      // print.size()
    void (*time)(t_dir *dir, size_t file);      // print.time()
    void (*name)(t_dir *dir, size_t file);      // print.name()
    void (*suffix)(t_dir *dir, size_t file);    // print.suffix()
    void (*arrow)(t_dir *dir, size_t file);     // print.arrow()
    void (*attr)(t_dir *dir, size_t file);      // print.attr()
    void (*acl)(t_dir *dir, size_t file);       // print.acl()
} t_print;

struct s_dir {
    t_file *files;      // pointer to colection of files in next var
    t_vector array;     // struct for manage array of files
    t_offset off;       // offsets in current directory
    t_info *info;       // access for other parametrs
    bool has_bc;        // true if char/block file (device) in dir
    DIR *dir;           // pointer to opened directory
};

struct s_info {
    t_get get;
    t_print print;
    void (*write)(t_dir *dir);              // determines type of print
    void (*read)(t_dir *dir);               // filter of hiden files
    int (*cmp)(const void *, const void *); // compare function in sort

    bool output_dst;        // 0 - terminal | 1 - file or other process
    t_time_type time_type;  // data/time type for -[tlgno]
};
