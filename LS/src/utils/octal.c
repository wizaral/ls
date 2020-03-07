#include "uls.h"

size_t mx_octal_off(const char *name, int len) {
    size_t result = 0;

    for (int i = 0; i < len; ++i)
        result += mx_isprint(name[i]) ? 1 : 4;
    return result;
}

size_t mx_octal_len(const char *name, int len) {
    size_t result = 0;

    for (int i = 0; i < len; ++i)
        result += MX_OCTAL(name[i]) ? 4 : 1;
    return result;
}

size_t mx_escape_len(const char *name, int len) {
    size_t result = 0;

    for (int i = 0; i < len; ++i) {
        if (MX_OCTAL(name[i]))
            result += MX_ESCAPE(name[i]) ? 1 : 3;
        ++result;
    }
    return result;
}
