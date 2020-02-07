#pragma once

// -rw-r--r--  1        abalabin  4242   2268 Dec 19 15:38 Makefile
// ACCESS      LINKS    LOGIN     GROUP  SIZE   TIME        ent->d.name
// This how -l flag standart works;

// структура файла содержит все-все поля

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

typedef enum e_time_type {
    access = 1 << 0,
    modification = 1 << 1,
    change = 1 << 2,
    creation = 1 << 3,
} t_time_type;

	// struct timespec st_atimespec;           /* time of last access */ \
	// struct timespec st_mtimespec;           /* time of last data modification */ \
	// struct timespec st_ctimespec;           /* time of last status change */ \
	// struct timespec st_birthtimespec;       /* time of file creation(birth) */

typedef struct s_print t_print;

// структура с файлами и директориями

typedef struct s_info {
    bool dst;
    t_print print;
    t_vector files;
    t_time_type time_type;

    void (*out)(t_info *info);
    void (*sort)(t_info *info);

} t_info;

// структура с функциями содержит указатели на необходимые параметры вывода

struct s_print {
    void (*print_inode)(t_info *info);
    void (*print_bsize)(t_info *info);
    void (*print_access)(t_info *info);
    void (*print_user)(t_info *info);
    void (*print_grp)(t_info *info);
    void (*print_fflags)(t_info *info);
    void (*print_size)(t_info *info);
    void (*print_time)(t_info *info);
    void (*print_name)(t_info *info);
    void (*print_name_add)(t_info *info);
};
