#include "libmx.h"

// #include <stdio.h>

// static void print(void *item) {
//     printf("%i, ", *(int *)item);
// }

// int main() {
//     t_vector *v = mx_create_vector(sizeof(int));
//     printf("%llu %llu %lu %lu\n", v->cap, v->size, v->bytes, _msize(v->arr));

//     for (int i = 0; i < 100; ++i) {
//         // mx_push_backward(v, &i);
//         mx_insert(v, 0, &i);
//         // mx_foreach_vector(v, print);
//         // printf("\n");
//     }
//     // mx_reverse_vector(v);
//     mx_foreach_vector(v, print);
//     printf("\n");

//     // for (int i = 0; i < 100; ++i) {
//     //     // mx_pop_backward(v);
//     //     mx_erase(v, 0);
//     //     mx_foreach_vector(v, print);
//     //     printf("\n");
//     // }

//     // mx_clear_vector(v);
//     // // v->size = 0;
//     // // printf("LOL\n");

//     // mx_foreach_vector(v, print);
//     // printf("\n");

//     // int item = 100;
//     // mx_assign_vector(v, 100, &item);

//     // mx_foreach_vector(v, print);
//     // printf("\n");

//     mx_delete_vector(v);
//     printf("SUCCESS!\n");
// }
