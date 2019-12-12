#include "libmx.h"

bool mx_checksort(t_cv *arr, size_t size, size_t bytes,
    int (*cmp)(t_cv *, t_cv *))
{
    if (arr && size > 0 && bytes > 0 && cmp) {
        for (t_ull i = bytes, end = size * bytes; i < end; i += bytes)
            if (cmp((t_uc *)arr + (i - bytes), (t_uc *)arr + i) > 0)
                return false;
        return true;
    }
    return false;
}
