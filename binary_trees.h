#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/* Basic Binary Tree Node Structure */
typedef struct binary_tree_s binary_tree_t;

struct binary_tree_s
{
    int n;
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/* Binary Search Tree Node Structure */
typedef struct bst_node_s
{
    int n;
    struct bst_node_s *parent;
    struct bst_node_s *left;
    struct bst_node_s *right;
} bst_node_t;

/* AVL Tree Node Structure */
typedef struct avl_node_s
{
    int n;
    struct avl_node_s *parent;
    struct avl_node_s *left;
    struct avl_node_s *right;
    int balance;
} avl_node_t;

/* Heap Node Structure */
typedef struct heap_s
{
    int n;
    struct heap_s *parent;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

/* Queue Structure for Level-Order Traversal */
typedef struct queue_s
{
    const void *data;
    struct queue_s *next;
} queue_t;

/* Function Prototypes */

/* Binary Tree Node Creation */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Binary Tree Traversal */
void binary_tree_print(const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_delete(binary_tree_t *tree);

/* Binary Search Tree Operations */
bst_node_t *bst_insert(bst_node_t **tree, int value);
bst_node_t *bst_search(const bst_node_t *tree, int value);
void bst_remove(bst_node_t **root, int value);

/* AVL Tree Operations */
avl_node_t *avl_insert(avl_node_t **tree, int value);
avl_node_t *array_to_avl(int *array, size_t size);

/* Heap Operations */
int heap_extract(heap_t **root);
heap_t *heap_insert(heap_t **root, int value);

/* Queue Operations */
void queue_push(queue_t **rear, const void *data);
void *queue_pop(queue_t **front);
int queue_is_empty(const queue_t *front);

/* Task Functions */
binary_tree_t *binary_tree_levelorder_successor(binary_tree_t *root, binary_tree_t *node);

#endif /* BINARY_TREES_H */
