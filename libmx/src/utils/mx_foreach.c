#include "libmx.h"

void mx_foreach(void *arr, t_ull size, size_t bytes, void(*f)(void *)) {
    if (arr && f && size && bytes)
        for (t_ull i = 0, end = size * bytes; i < end; i += bytes)
            f((t_uc *)arr + i);
}
