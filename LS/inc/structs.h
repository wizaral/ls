#pragma once
#include "uls.h"

typedef struct stat t_stat;
typedef struct dirent t_dirent;
typedef struct timespec t_timespec;

typedef struct s_dir t_dir;
typedef struct s_get t_get;
typedef struct s_info t_info;
typedef struct s_file t_file;
typedef struct s_offset t_offset;
typedef struct s_lengths t_lengths;
typedef struct s_printable t_printable;

typedef enum e_time_type t_time_type;

struct s_lengths {
    uint8_t inode;
    uint8_t bsize;
    uint8_t links;
    uint8_t user;
    uint8_t grp;
    uint8_t flags;
    uint8_t size;
    uint8_t time;
    uint8_t name;
};

struct s_printable {
    char *inode;
    char *bsize;
    char *links;
    char *user;
    char *grp;
    char *flags;
    char *size;
    char *time;
    char *name;
    char *arrow;
    char *attr;
    char *acl;
    char suffix;
    char access[11];
    // ... @
    // ... e
};

struct s_file {
    t_printable fields;
    t_lengths lengths;
    t_timespec time;
    // maybe need something ?
};

struct s_offset {
    uint8_t inode;      // length of longest inode
    uint8_t bsize;      // length of longest block size
    uint8_t links;      // length of longest amount of links
    uint8_t uid;        // length of longest user name/id
    uint8_t gid;        // length of longest group name/id
    uint8_t flags;      // length of longest inode
    uint8_t size;       // length of longest size
    uint8_t filename;   // length of longest filename

    size_t columns;         // number of columns in C out
    size_t rows;            // number of rows in C out
    size_t width;           // terminal width
    size_t x;               // current position in line
    size_t filename_tabs;   // tabs in longest filename
};

/*
 * st_atimespec;        time of last access
 * st_mtimespec;        time of last data modification
 * st_ctimespec;        time of last status change
 * st_birthtimespec;    time of file creation
 */

enum e_time_type {
    last_access = 0,
    modification = sizeof(t_timespec),
    change = sizeof(t_timespec) * 2,
    creation = sizeof(t_timespec) * 3,
};

struct s_get {
    void (*inode)(t_info *, t_dir *, t_file *, t_stat *);
    void (*bsize)(t_info *, t_dir *, t_file *, t_stat *);
    void (*access)(t_info *, t_dir *, t_file *, t_stat *);
    void (*links)(t_info *, t_dir *, t_file *, t_stat *);
    void (*user)(t_info *, t_dir *, t_file *, t_stat *);
    void (*grp)(t_info *, t_dir *, t_file *, t_stat *);
    void (*flags)(t_info *, t_dir *, t_file *, t_stat *);
    void (*size)(t_info *, t_dir *, t_file *, t_stat *);
    void (*time)(t_info *, t_dir *, t_file *, t_stat *);
    void (*name)(t_info *, t_dir *, t_file *, t_stat *);
    void (*suffix)(t_info *, t_dir *, t_file *, t_stat *);
    void (*arrow)(t_info *, t_dir *, t_file *, t_stat *);
    void (*attr)(t_info *, t_dir *, t_file *, t_stat *);
    void (*acl)(t_info *, t_dir *, t_file *, t_stat *);
};

struct s_dir {
    DIR *dir;       // pointer to opened directory
    char *name;     // current directory
    size_t len;     // length of directory name

    t_dirent *file; // current file on reading
    char *filename; // name of current file ["dirname/filename"]

    t_vector array; // struct for manage array of files
    t_offset off;   // offsets in current directory
    bool has_bc;    // true if char/block file (device) in dir
};

struct s_info {
    void (*write)(t_info *, t_dir *);       // determines type of print
    t_dirent *(*read)(DIR *);               // filter of hiden files
    int (*cmp)(const void *, const void *); // compare function in sort
    void (*print_name)(t_file *);           // out fname colored/normal
    void (*foreach)(t_vector *, void (*)(void *));  // reverse or not
    void (*recursion)(t_info *, t_dir *);   // recursion in directories

    t_get get;              // functions for getting files info
    bool output_dst;        // 0 - terminal | 1 - file or other process
    bool return_val;        // 0 - good | 1 - any error
    t_time_type time_type;  // data/time type for -[tlgno]

    t_vector files;         // only files from arguments
    t_vector directories;   // dirs from arguments
};
