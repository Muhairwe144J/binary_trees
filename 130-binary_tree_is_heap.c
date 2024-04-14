#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is a valid binary heap.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid binary heap, otherwise 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) &&
            binary_tree_is_heap(tree->right));
}
