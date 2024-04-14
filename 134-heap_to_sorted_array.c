#include "binary_trees.h"

/**
 * heapify_down - Restores the max heap property starting from a node.
 * @root: A pointer to the root node of the heap.
 */
static void heapify_down(heap_t *root)
{
    heap_t *largest = NULL;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > root->n)
        largest = left;
    else
        largest = root;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        int temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * heap_to_sorted_array - Converts a binary max heap to a sorted array.
 * @heap: A pointer to the root node of the heap.
 * @size: Pointer to the size of the sorted array.
 *
 * Return: A pointer to the sorted array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i;

    if (heap == NULL || size == NULL)
        return (NULL);

    *size = binary_tree_size(heap);

    array = malloc(*size * sizeof(int));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < *size; i++)
    {
        array[i] = heap->n;
        heap->n = heap_extract(&heap);
        heapify_down(heap);
    }

    return (array);
}
