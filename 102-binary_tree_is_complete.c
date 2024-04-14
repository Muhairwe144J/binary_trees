#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int complete = 1;
    int flag = 0;
    queue_t *queue = NULL;

    if (!tree)
        return (0);

    queue = enqueue(queue, (binary_tree_t *)tree);

    while (queue)
    {
        binary_tree_t *node = dequeue(&queue);

        if (node->left)
        {
            if (flag)
                complete = 0;
            else
                queue = enqueue(queue, node->left);
        }
        else
        {
            flag = 1;
        }

        if (node->right)
        {
            if (flag)
                complete = 0;
            else
                queue = enqueue(queue, node->right);
        }
        else
        {
            flag = 1;
        }
    }

    return (complete);
}
