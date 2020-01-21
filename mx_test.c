#include "libmx/inc/libmx.h"
#include <stdio.h>
#include <time.h>

static inline void print(void *item) {
    printf("%i, ", *(int *)item);
}

static void fprint(t_flist_node *node) {
    print(node->data);
}

static void print2(t_queue *q) {
    printf("PRINT2!\n");
    for (t_i64 i = 0; i < q->size; ++i)
        printf("%i, ", *(int *)((t_uc *)q->arr + i * q->bytes));
    printf("\n");
}

static void vector_case() {
    t_vector *v = mx_create_vector(sizeof(int));
    int r;
    printf("%llu %llu %lu %zu\n", v->cap, v->size, v->bytes, malloc_size(v->arr));

    for (int i = 0; i < 25; ++i) {
        r = rand() % 10;
        mx_push_backward(v, &r);
        mx_foreach_vector(v, print);
        printf("\n");
    }
    printf("CREATED\n");

    mx_reverse_vector(v);
    mx_foreach_vector(v, print);
    printf("\nREVERSED\n");

    for (int i = 0; i < 25; i++) {
        r = rand() % 10;
        mx_insert(v, i, &r);
        mx_foreach_vector(v, print);
        printf("INSERTED: %d\n", r);
    }
    printf("\nINSERTED\n");

    for (int i = 0; i < 25; i++){
        r = rand() % v->size;
        mx_erase(v, r);
        mx_foreach_vector(v, print);
        printf("ERASED: %d\n", r);
    }
    printf("\nERASED\n");

    for (int i = 0; i < 15; i++) {
        mx_pop_backward(v);
        mx_foreach_vector(v, print);
        printf("\n");
    }
    printf("\nPOPED BACK\n");

    for (int i = 0; i < 45; i++) {
        r = rand() % 10;
        mx_push_backward(v, &r);
        mx_foreach_vector(v, print);
        printf("\n");
    }
    printf("\nPUSHED\n");
    // int *front = mx_get_front(v);
    // int *back = mx_get_back(v);
    // printf("Front: %d\nBack: %d\n", *front, *back);

    // mx_assign_vector(v, 16, &r);
    // mx_foreach_vector(v, print);
    // printf("\nASSIGNED\n");

    mx_clear_vector(v);
    mx_foreach_vector(v, print);
    printf("\nCLEARED\n");

    mx_delete_vector(v);
    printf("\nDELETED\n");
}

static void queue_case() {
    t_queue *q = mx_create_queue(sizeof(int));
    int r;

    for (int i = 0; i < 24; i++) {
        r = rand() % 10;
        mx_enqueue(q, &r);
        mx_foreach_queue(q, print);
        printf("\n1 head: %llu %i\ntail: %llu %i\n", q->head, *(int *)mx_front(q), q->tail, *(int *)mx_rear(q));
    }
    printf("\n");
    print2(q);

    for (int i = 300; i < 305; i++) {
        mx_dequeue(q);
        mx_enqueue(q, &i);
        //printf("2 head: %llu %i\ntail: %llu %i\n", q->head, *(int *)mx_front(q), q->tail, *(int *)mx_rear(q));
    }
    printf("\n");
    print2(q);

    r = rand() % 10;

    mx_dequeue(q);
    mx_enqueue(q, &r);
    print2(q);

    r = rand() % 10;

    mx_enqueue(q, &r);
    print2(q);

    mx_foreach_queue(q, print);

    int *front = mx_front(q);
    int *rear = mx_rear(q);
    printf("\nFront: %d\nRear: %d\nSize: %lld\n", *front, *rear, q->size);

    mx_foreach_queue(q, print);
    printf("\n");

    mx_delete_queue(q);
    printf("\nDELETED\n");

    // mx_foreach_queue(q, print);
    // printf("\n");
}

static void stack_case() {
    t_stack *s = mx_create_stack(sizeof(int));
    int *top;
    int r;

    for (int i = 0; i < 40; i++) {
        r = rand() % 10;
        mx_push(s, &r);
        mx_foreach_stack(s, print);
        printf("\n");
    }

    for (int i = 0; i < 41; i++) {
        top = mx_top(s);
        mx_foreach_stack(s, print);
        mx_pop(s);
        printf("TOP WAS: %d\n", *top);
    }

    mx_delete_stack(s);
    printf("\nDELETED\n");

    // mx_foreach_stack(s, print);
    // printf("\n");
}

static void flist_case() {
    t_flist *l = mx_fcreate_list();
    int r;

    for (int i = 0; i < 16; ++i) {
        mx_fpush_back(l, &i);
        mx_fforeach_list(l, fprint);
        printf("\n");
    }
    printf("\nCREATED\n");
    for (int i = 0; i < 25; i++) {
        r = rand() % 10;
        mx_fpush_index(l, &r, i);
        mx_fforeach_list(l, fprint);
        printf("\n");
    }
    printf("\nFPUSH_INDEX\n");

    for (int i = 0; i < 40; i++) {
        r = rand() % 50;
        mx_fpop_index(l, r);
        mx_fforeach_list(l, fprint);
        printf("POS: %d\n", r);
    }
    printf("\nFPOP_INDEX\n");

    for (int i = 0; i < 40; i++) {
        r = rand() % 10;
        mx_fpush_front(l, &r);
        mx_fforeach_list(l, fprint);
        printf("\n");
    }
    printf("\nFPUSH_FRONT\n");

    int **arr = (int **)mx_flist_to_array(l);
    for (int i = 0; i < l->size; ++i)
        printf("%d, ", *arr[i]);
    printf("\nARRAY\n");

    mx_fcheck_tail(l);
    t_ll size = mx_fcheck_size(l);
    mx_fcheck_cycle(l);

    printf("SIZE: %lld\n", size);

    mx_fclear_list(l);
    mx_fforeach_list(l, fprint);
    printf("\nCLEARED\n");

    mx_fdelete_list(l);
    printf("\nDELETED\n");
}

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc > 1) {
        switch (mx_atoll(argv[1])) {
            case 1:
                vector_case();
                break;
            case 2:
                queue_case();
                break;
            case 3:
                stack_case();
                break;
            case 4:
                flist_case();
                break;
            }
    }
}
