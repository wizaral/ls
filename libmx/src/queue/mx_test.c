#include "../../inc/libmx.h"

#include <stdio.h>

static void print(void *item) {
    printf("%i, ", *(int *)item);
}

int main() {
    t_queue *q = mx_create_queue(16);

    for (int i = 0; i < 64; i++) {
        mx_enqueue(q, &i);
        mx_foreach_queue(q, print);
        printf("\n");
    }

    int *item = mx_dequeue(q);
    printf("%d\n", *item);
    mx_foreach_queue(q, print);

    int *front = mx_front(q);
    int *rear = mx_rear(q);

    printf("\nFront: %d\nRear: %d\n", *front, *rear);

    mx_foreach_queue(q, print);

    mx_delete_queue(&q);
}
