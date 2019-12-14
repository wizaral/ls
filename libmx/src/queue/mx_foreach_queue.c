#include "libmx.h"

void mx_foreach_queue(t_queue *q, void (*f)(void *)) {
    if (q && q->arr && f) {
        t_ull byte = q->bytes;
        t_ull endt = q->tail * byte;
        t_ull endc = q->cap * byte;

        if (q->head <= q->tail)
            for (t_ull i = q->head * byte; i <= endt; i += byte)
                f((t_uc *)q->arr + i);
        else {
            for (t_ull i = q->head * byte; i < endc; i += byte)
                f((t_uc *)q->arr + i);
            for (t_ull i = 0; i <= endt; i += byte)
                f((t_uc *)q->arr + i);
        }
    }
}
