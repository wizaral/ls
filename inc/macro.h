#pragma once
#include "uls.h"

#define MX_ISBLK(x)    (((x) & S_IFMT) == S_IFBLK)     // block special
#define MX_ISCHR(x)    (((x) & S_IFMT) == S_IFCHR)     // char special
#define MX_ISDIR(x)    (((x) & S_IFMT) == S_IFDIR)     // directory
#define MX_ISFIF(x)    (((x) & S_IFMT) == S_IFIFO)     // fifo or socket
#define MX_ISREG(x)    (((x) & S_IFMT) == S_IFREG)     // regular file
#define MX_ISLNK(x)    (((x) & S_IFMT) == S_IFLNK)     // symbolic link
#define MX_ISSCK(x)    (((x) & S_IFMT) == S_IFSOCK)    // socket
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define MX_ISWHT(x)    (((x) & S_IFMT) == S_IFWHT)     // whiteout
#endif

#define MX_ISUID(m)    (((m) & S_ISUID) != 0)
#define MX_ISGID(m)    (((m) & S_ISGID) != 0)
#define MX_ISVTX(m)    (((m) & S_ISVTX) != 0)

#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)

#define MX_EXIST(x) mx_strchr(MX_FLAGS, x)
#define MX_WRITE(x) mx_strchr("l1Cxm", x)
#define MX_LADDS(x) mx_strchr("Tnog", x)
#define MX_OTHER(x) mx_strchr("RGrisd", x)

#define MX_DOT1(x) ((x)[0] == '.' && (x)[1] == '\0')
#define MX_DOT2(x) ((x)[0] == '.' && (x)[1] == '.' && (x)[2] == '\0')
#define MX_DOTS(x) (MX_DOT1(x) || MX_DOT2(x))
