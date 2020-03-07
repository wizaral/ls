#include "uls.h"

void mx_file_flags(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    ++info;
    ++dir;
    ++file;
    ++st;
}

/*
#define SAPPEND(s)                        \
    {                                     \
        if (prefix != NULL)               \
            (void)strcat(string, prefix); \
        (void)strcat(string, s);          \
        prefix = ",";                     \
    }
*/

// char *flags_to_string(flags, def) u_long flags; char *def; {
//     static char string[128];
//     char *prefix;

//     string[0] = '\0';
//     prefix = NULL;
//     if (flags & UF_APPEND)
//         SAPPEND("uappnd");
//     if (flags & UF_IMMUTABLE)
//         SAPPEND("uchg");
//     if (flags & UF_NODUMP)
//         SAPPEND("nodump");
//     if (flags & UF_OPAQUE)
//         SAPPEND("opaque");
//     if (flags & SF_APPEND)
//         SAPPEND("sappnd");
//     if (flags & SF_ARCHIVED)
//         SAPPEND("arch");
//     if (flags & SF_IMMUTABLE)
//         SAPPEND("schg");
//     return (prefix == NULL && def != NULL ? def : string);
// }
