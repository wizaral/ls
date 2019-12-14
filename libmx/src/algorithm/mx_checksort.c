#include "libmx.h"

bool mx_checksort(t_cv *arr, size_t size, size_t bytes,
    int (*cmp)(t_cv *, t_cv *))
{
    if (arr && size > 0 && bytes > 0 && cmp) {
        t_ull end = (size - 1) * bytes;

        for (t_ull i = 0; i < end; i += bytes)
            if (cmp((t_uc *)arr + i, (t_uc *)arr + (i + bytes)) > 0)
                return false;
        return true;
    }
    return false;
}
