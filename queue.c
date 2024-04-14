#include <stdlib.h>
#include "binary_trees.h"

/**
 * queue_push - adds a node to the end of the queue
 * @rear: pointer to rear of the queue
 * @data: data to be added to the queue
 * Return: pointer to the newly added node
 */
void queue_push(queue_t **rear, const void *data)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (!new_node)
        return;

    new_node->data = data;
    new_node->next = NULL;

    if (*rear)
    {
        (*rear)->next = new_node;
    }
    *rear = new_node;
}

/**
 * queue_pop - removes a node from the beginning of the queue
 * @front: pointer to the front of the queue
 * Return: data of the removed node
 */
void *queue_pop(queue_t **front)
{
    queue_t *temp;
    void *data;

    if (!*front)
        return NULL;

    temp = *front;
    data = temp->data;
    *front = (*front)->next;

    free(temp);

    return (void *)data;
}

/**
 * queue_is_empty - checks if a queue is empty
 * @front: pointer to the front of the queue
 * Return: 1 if empty, 0 otherwise
 */
int queue_is_empty(const queue_t *front)
{
    return (front == NULL);
}
