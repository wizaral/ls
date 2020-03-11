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

struct s_lengths {
    uint8_t inode;
    uint8_t bsize;
    uint8_t links;
    uint8_t user;
    uint8_t grp;
    uint8_t size;
    uint8_t time;
    uint8_t name;
    uint8_t suffix;
    uint8_t arrow;
};

struct s_printable {
    char *inode;
    char *bsize;
    char *links;
    char *user;
    char *grp;
    char *size;
    char *time;
    char *name;
    char *arrow;
    char suffix;
    char access[12];
};

struct s_file {
    t_printable fields;
    t_lengths lengths;
    t_timespec time;
    int64_t size;
    uint16_t mode;
};

struct s_offset {
    size_t columns;     // number of columns in C out
    size_t rows;        // number of rows in C out
    size_t width;       // terminal width
    size_t x;           // current position in line
    size_t name_tabs;   // tabs in longest filename

    uint8_t inode;      // length of longest inode
    uint8_t bsize;      // length of longest block size
    uint8_t links;      // length of longest amount of links
    uint8_t user;       // length of longest user name/id
    uint8_t grp;        // length of longest group name/id
    uint8_t size;       // length of longest size
    uint8_t name;       // length of longest filename
};

/*
 * st_atimespec;        time of last access
 * st_mtimespec;        time of last data modification
 * st_ctimespec;        time of last status change
 * st_birthtimespec;    time of file creation
 */

enum e_time_type {
    last_access = 0,
    modification = 1,
    change = 2,
    creation = 3,
};

typedef enum e_time_type t_time_type;

struct s_get {
    void (*inode)(t_dir *, t_file *, t_stat *);
    void (*bsize)(t_dir *, t_file *, t_stat *);
    void (*access)(t_dir *, t_file *, t_stat *);
    void (*links)(t_dir *, t_file *, t_stat *);
    void (*user)(t_dir *, t_file *, t_stat *);
    void (*grp)(t_dir *, t_file *, t_stat *);
    void (*size)(t_dir *, t_file *, t_stat *);
    void (*time)(t_dir *, t_file *, t_stat *);
    void (*name)(t_dir *, t_file *, t_stat *);
    void (*suffix)(t_dir *, t_file *, t_stat *);
    void (*arrow)(t_dir *, t_file *, t_stat *);
};

struct s_dir {
    DIR *dir;       // pointer to opened directory
    char *name;     // current directory
    size_t len;     // length of directory name
    int64_t total;  // total block count

    t_dirent *file; // current file on reading
    char *filename; // name of current file ["dirname/filename"]

    t_vector array; // struct for manage array of files
    t_offset off;   // offsets in current directory
};

struct s_info {
    void (*write)(t_info *, t_dir *);       // determines type of print
    t_dirent *(*read)(DIR *);               // filter of hiden files
    int (*cmp)(const void *, const void *); // compare function in sort
    void (*print_total)(t_info *, t_dir *); // print total bsize
    void (*print_name)(t_file *);           // out fname colored/normal
    void (*recursion)(t_info *, t_dir *);   // recursion in directories

    t_get get;              // functions for getting files info
    bool output_dst;        // 0 - terminal | 1 - file or other process
    bool return_val;        // 0 - good | 1 - any error
    bool reverse;           // 0 - normal | 1 - reversed
    bool filedir;           // 0 - default | 1 - dir like file
    t_time_type time_type;  // data/time type for -[tlgno]

    t_vector files;         // files from arguments
    t_vector dirs;          // dirs from arguments
};
