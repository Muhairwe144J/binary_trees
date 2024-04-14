#include <stdio.h>
#include "binary_trees.h"

void print_tree(const binary_tree_t *tree, int space)
{
    if (!tree)
        return;

    space += 10;

    print_tree(tree->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", tree->n);

    print_tree(tree->left, space);
}

void binary_tree_print(const binary_tree_t *tree)
{
    print_tree(tree, 0);
}
