#pragma once

typedef struct s_tree_node {
    void *data;
    struct s_tree_node *left;
    struct s_tree_node *right;
} t_tree_node;

typedef struct s_tree {
    size_t size;
    t_tree_node *root;
    int (*cmp)(const void *, const void *);
} t_tree;

t_tree *mx_create_tree(int (*cmp)(const void *, const void *));
