#include "binary_trees.h"
#include "122-array_to_avl.c"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (array_to_avl(array, 0, size - 1, NULL));
}

/**
 * array_to_avl - Recursive helper function to build an AVL tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @start: The starting index of the current subarray.
 * @end: The ending index of the current subarray.
 * @parent: A pointer to the parent node of the current subtree.
 *
 * Return: A pointer to the root node of the created AVL subtree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t start, size_t end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    size_t mid = (start + end) / 2;
    avl_t *new_node = malloc(sizeof(avl_t));

    if (new_node == NULL)
        return (NULL);

    new_node->n = array[mid];
    new_node->parent = parent;
    new_node->left = array_to_avl(array, start, mid - 1, new_node);
    new_node->right = array_to_avl(array, mid + 1, end, new_node);

    return (new_node);
}
