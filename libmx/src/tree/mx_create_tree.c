#include "libmx.h"

t_tree *mx_create_tree(int (*cmp)(const void *, const void *)) {
    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));

    if (tree) {
        tree->cmp = cmp;
        tree->root = NULL;
        tree->size = 0;
    }
    return tree;
}
