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
 * heap_extract - Extracts the root node from a binary max heap.
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node or 0 if the heap is empty.
 */
int heap_extract(heap_t **root)
{
    int value;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    heapify_down(*root);

    return (value);
}

