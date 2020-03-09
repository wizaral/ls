#include "uls.h"

void mx_file_flags(t_dir *dir, t_file *file, t_stat *st) {
    ++dir;
    ++file;
    ++st;
}

// #define SAPPEND(s)                        \
//     {                                     \
//         if (prefix != NULL)               \
//             strcat(string, prefix);       \
//         strcat(string, s);                \
//         prefix = ",";                     \
//     }

// char *flags_to_string(flags, def) {
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

// static void get_flags(t_const *cnst, char *str) {
//     char *tmp = NULL;

//     tmp = cnst->flags;
//     if (cnst->flags != NULL) {
//         cnst->flags = mx_strjoin(tmp, ",");
//         free(tmp);
//     }
//     tmp = cnst->flags;
//     cnst->flags = mx_strjoin(tmp, str);
//     free(tmp);
// }

// static void root_flags(t_const *cnst, struct stat st) {
//     if (st.st_flags & SF_NOUNLINK) // sunlnk
//         get_flags(cnst, "sunlnk");
//     if (st.st_flags & SF_RESTRICTED) // restricted
//         get_flags(cnst, "restricted");
//     if (st.st_flags & UF_HIDDEN) // hidden
//         get_flags(cnst, "hidden");
//     if (st.st_flags & UF_COMPRESSED) // compressed 
//         get_flags(cnst, "compressed");
// }

// static void user_flags(t_const *cnst, struct stat st) {
//     if (st.st_flags & UF_APPEND)
//         get_flags(cnst, "uappnd");
//     if (st.st_flags & UF_IMMUTABLE)
//         get_flags(cnst, "uchg");
//     if (st.st_flags & UF_NODUMP)
//         get_flags(cnst, "nodump");
//     if (st.st_flags & UF_OPAQUE)
//         get_flags(cnst, "opaque");
//     if (st.st_flags & SF_APPEND)
//         get_flags(cnst, "sappnd");
//     if (st.st_flags & SF_ARCHIVED)
//         get_flags(cnst, "arch");
//     if (st.st_flags & SF_IMMUTABLE)
//         get_flags(cnst, "schg");
// }

// void mx_get_flags_for_file(t_const *cnst, struct stat st) {
//     cnst->flags = NULL;
//     user_flags(cnst, st);
//     root_flags(cnst, st);
//     if (cnst->flags == NULL)
//         cnst->flags = "-";
// }
