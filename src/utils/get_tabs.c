#include "uls.h"

int mx_get_tabs(int size) {
    int count = 0;

    for (; size >= 8; size -= 8)
        ++count;
    return count;
}
