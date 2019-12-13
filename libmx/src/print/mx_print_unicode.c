#include "libmx.h"

// typedef struct s_unicode {
//     int a;  // and
//     int c;  // symbol
//     int l;  // length
//     int o;  // or
// } t_unicode;

// static void print_unicode(t_unicode *u, const int fd) {
//     char s = 0;

//     for (int j = u->l * 6; j >= 0; write(fd, &s, 1), j -= 6, s = 0)
//         s = j == u->l * 6 ? (u->c >> j & u->a) | u->o : (u->c >> j & 63) | 128;
// }

// void mx_print_unicode(wchar_t c) {
//     if (c < 128)
//         print_unicode(c, 0x7F, 0x00, 0);
//     else if (c < 2048)
//         print_unicode(c, 0x1F, 0xC0, 1);
//     else if (c < 65536)
//         print_unicode(c, 0x0F, 0xE0, 2);
//     else
//         print_unicode(c, 0x07, 0xF0, 3);
// }

static void print_large(wchar_t c, char *cc) {
    cc[0] = (c >> 18 & 0x07) | 0xF0;
    cc[1] = (c >> 12 & 0x3F) | 0x80;
    cc[2] = (c >> 6 & 0x3F) | 0x80;
    cc[3] = (c & 0x3F) | 0x80;
}

void mx_print_unicode(wchar_t c, const int fd) {
    if (fd >= 0) {
        char cc[5] = {0};

        if (c < 0x80) 
            cc[0] = c & 0x7F;
        else if (c < 0x0800) {
            cc[0] = (c >> 6 & 0x1F) | 0xC0;
            cc[1] = (c & 0x3F) | 0x80;
        }
        else if (c < 0x010000) {
            cc[0] = (c >> 12 & 0x0F) | 0xE0;
            cc[1] = (c >> 6 & 0x3F) | 0x80;
            cc[2] = (c & 0x3F) | 0x80;
        }
        else
            print_large(c, cc);
        write(fd, cc, mx_strlen(cc));
    }
}
