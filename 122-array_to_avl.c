#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;

    if (array == NULL || size == 0)
        return (NULL);

    for (size_t i = 0; i < size; i++)
    {
        if (avl_insert(&root, array[i]) == NULL)
        {
            while (root->parent != NULL)
                root = root->parent;
            return (root);
        }
    }

    while (root->parent != NULL)
        root = root->parent;

    return (root);
}
