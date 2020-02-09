#pragma once
#include "uls.h"

// #define S_ISBLK(m)      (((m) & S_IFMT) == S_IFBLK)     // block special
// #define S_ISCHR(m)      (((m) & S_IFMT) == S_IFCHR)     // char special
// #define S_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)     // directory
// #define S_ISFIFO(m)     (((m) & S_IFMT) == S_IFIFO)     // fifo or sock
// #define S_ISREG(m)      (((m) & S_IFMT) == S_IFREG)     // regular file
// #define S_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)     // symbolic link
// #define S_ISSOCK(m)     (((m) & S_IFMT) == S_IFSOCK)    // socket
// #if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
// #define S_ISWHT(m)      (((m) & S_IFMT) == S_IFWHT)     // whiteout
// #endif

#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)
