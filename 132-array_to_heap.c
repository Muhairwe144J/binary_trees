#include "binary_trees.h"

/**
 * array_to_heap - Builds a max heap from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the constructed heap.
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t **heap_array;
    heap_t *root = NULL;
    size_t i;

    if (array == NULL || size == 0)
        return (NULL);

    heap_array = malloc(sizeof(heap_t *) * size);
    if (heap_array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        heap_array[i] = heap_insert(&root, array[i]);
        if (heap_array[i] == NULL)
        {
            free(heap_array);
            return (NULL);
        }
    }

    free(heap_array);
    return (root);
}
