#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: A pointer to the node containing the found value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);

    while (tree != NULL)
    {
        if (value == tree->n)
            return ((bst_t *)tree);

        if (value < tree->n)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return (NULL);
}
