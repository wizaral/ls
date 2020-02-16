#pragma once
#include "uls.h"

#define MX__ISBLK(m)    (((m) & S_IFMT) == S_IFBLK)     // block special
#define MX__ISCHR(m)    (((m) & S_IFMT) == S_IFCHR)     // char special
#define MX__ISDIR(m)    (((m) & S_IFMT) == S_IFDIR)     // directory
#define MX__ISFIFO(m)   (((m) & S_IFMT) == S_IFIFO)     // fifo or sock
#define MX__ISREG(m)    (((m) & S_IFMT) == S_IFREG)     // regular file
#define MX__ISLNK(m)    (((m) & S_IFMT) == S_IFLNK)     // symbolic link
#define MX__ISSOCK(m)   (((m) & S_IFMT) == S_IFSOCK)    // socket
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define MX__ISWHT(m)    (((m) & S_IFMT) == S_IFWHT)     // whiteout
#endif

#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)
