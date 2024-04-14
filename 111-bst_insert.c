#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the newly inserted node or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current;

    if (tree == NULL)
        return (NULL);

    /* If tree is empty, create a new node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    current = *tree;

    /* Traverse the tree to find the correct position to insert the new node */
    while (current)
    {
        /* If the value is less than the current node's value, go left */
        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = binary_tree_node(current, value);
                if (new_node == NULL)
                    return (NULL);
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        /* If the value is greater than the current node's value, go right */
        else if (value > current->n)
        {
            if (current->right == NULL)
            {
                new_node = binary_tree_node(current, value);
                if (new_node == NULL)
                    return (NULL);
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
        /* If the value already exists, do not insert */
        else
        {
            return (NULL);
        }
    }

    return (NULL);
}
