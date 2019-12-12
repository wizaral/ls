#include "libmx.h"

#include <stdio.h>

static inline void print(void *item) {
    printf("%i, ", *(int *)item);
}

static void fprint(t_flist_node *node) {
    print(node->data);
}

static void vector_case() {
    t_vector *v = mx_create_vector(sizeof(int));
    printf("%llu %llu %lu %zu\n", v->cap, v->size, v->bytes, malloc_size(v->arr));

    for (int i = 0; i < 32; ++i) {
        mx_push_backward(v, &i);
        mx_foreach_vector(v, print);
        printf("\n");
    }

    mx_reverse_vector(v);
    mx_foreach_vector(v, print);
    printf("\n");

    int item = 0;
    mx_insert(v, 2, &item);
    mx_foreach_vector(v, print);
    printf("\nINSERTED\n");
    
    mx_erase(v, 0);
    mx_foreach_vector(v, print);
    printf("\nERASED\n");

    mx_pop_backward(v);
    mx_foreach_vector(v, print);
    printf("\nPOPED BACK\n");

    mx_push_backward(v, &item);
    mx_foreach_vector(v, print);
    printf("\nPUSHED\n");

    int *front = mx_get_front(v);
    int *back = mx_get_back(v);
    printf("Front: %d\nBack: %d\n", *front, *back);

    mx_assign_vector(v, 16, &item);
    mx_foreach_vector(v, print);
    printf("\nASSIGNED\n");

    mx_clear_vector(v);
    mx_foreach_vector(v, print);
    printf("\nCLEARED\n");

    mx_delete_vector(v);
    printf("\nDELETED\n");
}

static void queue_case() {
    t_queue *q = mx_create_queue(sizeof(int));

    for (int i = 0; i < 32; i++) {
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

static void stack_case() {
    t_stack *s = mx_create_stack(sizeof(int));

    for (int i = 0; i < 40; i++) {
        mx_push(s, &i);
        mx_foreach_stack(s, print);
        printf("\n");
    }

    int *top = mx_pop(s);
    printf("\nPop: %d\n", *top);
    mx_foreach_stack(s, print);
    printf("\n");

    top = mx_top(s);
    printf("Top: %d\n", *top);
    mx_foreach_stack(s, print);
    printf("\n");
    
    mx_delete_stack(&s);

    mx_foreach_stack(s, print);
    printf("\n");
}

static void flist_case() {
    t_flist *l = mx_fcreate_list();

    for (int i = 0; i < 16; ++i) {
        mx_fpush_back(l, &i);
        mx_fforeach_list(l, fprint);
        printf("\n");
    }
    int item = 69;
    mx_fpush_index(l, &item, 1);
    mx_fforeach_list(l, fprint);
    printf("\nFPUSH_INDEX\n");

    mx_fpop_index(l, 1);
    mx_fforeach_list(l, fprint);
    printf("\nFPOP_INDEX\n");

    mx_fpush_front(l, &item);
    mx_fforeach_list(l, fprint);
    printf("\nFPUSH_FRONT\n");

    int **arr = (int **)mx_flist_to_array(l);
    for (int i = 0; i < 16; ++i)
        printf("%d, ", *arr[i]);
    printf("\nARRAY\n");

    mx_fcheck_tail(l);
    t_ll size = mx_fcheck_size(l);
    mx_fcheck_cycle(l);

    printf("SIZE: %lld\n", size);

    mx_fclear_list(l);
    mx_fforeach_list(l, fprint);
    printf("\nCLEARED\n");

    mx_fdelete_list(&l);
    printf("\nDELETED\n");
}

int main(int argc, char *argv[]) {
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
