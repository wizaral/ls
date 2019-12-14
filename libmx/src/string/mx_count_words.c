#include "libmx.h"

int mx_count_words(t_cc *str, char c) {
    if (str) {
        int words = 0;

        while (*str) {
            for (; *str && *str == c; ++str);
            if (*str && *str != c) {
                for (; *str && *str != c; ++str);
                ++words;
            }
        }
    }
    return str ? words : -1;
}
