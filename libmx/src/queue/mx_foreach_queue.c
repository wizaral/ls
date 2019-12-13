#include "libmx.h"

void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && f) {
        t_ull endt = q->tail * q->bytes;
        t_ull endc = q->cap * q->bytes;

        if (q->head <= q->tail)
            for (t_ull i = q->head * q->bytes; i <= endt; i += q->bytes)
                f((t_uc *)q->arr + i);
        else {
            for (t_ull i = q->head * q->bytes; i < endc; i += q->bytes)
                f((t_uc *)q->arr + i);
            for (t_ull i = 0; i <= endt; i += q->bytes)
                f((t_uc *)q->arr + i);
        }
    }
}
