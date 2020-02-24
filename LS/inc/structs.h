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
    uint8_t time;
    uint8_t name;
} t_lengths;

typedef struct s_printable {
    char *inode;
    char *bsize;
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
    char suffix;
    char access[11];
    char name[255];
} t_printable;

typedef struct s_file {
    struct timespec time;
    // ...
    t_printable fields;
} t_file;

typedef struct s_offset {
    // ...
    size_t file_name;   // size of longest word in file vectors
    int file_name_tabs; // tabs in longest word
    int columns;        // number of columns in C out
    int rows;           // number of rows in C out
    int width;          // terminal width
    int x;              // current position in x
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
    void (*inode)(t_dir *dir, t_file *file, struct stat *st);
    void (*bsize)(t_dir *dir, t_file *file, struct stat *st);
    void (*access)(t_dir *dir, t_file *file, struct stat *st);
    void (*links)(t_dir *dir, t_file *file, struct stat *st);
    void (*user)(t_dir *dir, t_file *file, struct stat *st);
    void (*grp)(t_dir *dir, t_file *file, struct stat *st);
    void (*flags)(t_dir *dir, t_file *file, struct stat *st);
    void (*size)(t_dir *dir, t_file *file, struct stat *st);
    void (*time)(t_dir *dir, t_file *file, struct stat *st);
    void (*name)(t_dir *dir, t_file *file, struct stat *st);
    void (*suffix)(t_dir *dir, t_file *file, struct stat *st);
    void (*arrow)(t_dir *dir, t_file *file, struct stat *st);
    void (*attr)(t_dir *dir, t_file *file, struct stat *st);
    void (*acl)(t_dir *dir, t_file *file, struct stat *st);
} t_get;

struct s_dir {
    char *name;             // current directory
    t_file *files;          // pointer to colection of files in next var
    t_vector array;         // struct for manage array of files
    t_offset off;           // offsets in current directory
    t_info *info;           // access for other parametrs
    bool has_bc;            // true if char/block file (device) in dir
    DIR *dir;               // pointer to opened directory
    struct dirent *file;    // current file pointer
};

struct s_info {
    void (*write)(t_dir *dir);              // determines type of print
    struct dirent *(*read)(t_dir *dir);     // filter of hiden files
    int (*cmp)(const void *, const void *); // compare function in sort

    t_get get;
    bool output_dst;        // 0 - terminal | 1 - file or other process
    t_time_type time_type;  // data/time type for -[tlgno]
};
