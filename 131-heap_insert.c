#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_up - Heapify the tree upwards after insertion.
 * @node: A pointer to the inserted node.
 */
void heapify_up(heap_t **node)
{
    heap_t *temp;

    while (*node && (*node)->parent && (*node)->n > (*node)->parent->n)
    {
        temp = (*node)->parent->parent;

        if ((*node)->parent->parent)
        {
            if ((*node)->parent->parent->left == (*node)->parent)
                (*node)->parent->parent->left = *node;
            else
                (*node)->parent->parent->right = *node;
        }

        if ((*node)->parent->left == *node)
        {
            (*node)->parent->left = (*node)->right;
            if ((*node)->right)
                (*node)->right->parent = (*node)->parent;
            (*node)->right = (*node)->parent;
        }
        else
        {
            (*node)->parent->right = (*node)->left;
            if ((*node)->left)
                (*node)->left->parent = (*node)->parent;
            (*node)->left = (*node)->parent;
        }

        (*node)->parent->parent = *node;
        (*node)->parent = temp;

        if ((*node)->parent == NULL)
            *node = (*node)->right;
    }
}

/**
 * heap_insert - Inserts a value into a binary max heap.
 * @root: A pointer to the root node of the binary heap.
 * @value: The value to insert.
 *
 * Return: A pointer to the inserted node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;

    while (parent->left && parent->right)
    {
        if (binary_tree_is_perfect(parent->left) &&
            !binary_tree_is_perfect(parent->right))
            parent = parent->right;
        else
            parent = parent->left;
    }

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    heapify_up(&new_node);

    return (new_node);
}
