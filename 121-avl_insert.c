#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A pointer to the root node of the AVL tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&(*tree)->left, value);
        if ((*tree)->left)
            (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&(*tree)->right, value);
        if ((*tree)->right)
            (*tree)->right->parent = *tree;
    }
    else
        return (NULL);

    return (*tree);
}
