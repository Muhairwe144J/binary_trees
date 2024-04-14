#include "binary_trees.h"

int count_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int is_complete(const binary_tree_t *tree, int index, int count)
{
    if (!tree)
        return 1;

    if (index >= count)
        return 0;

    return is_complete(tree->left, 2 * index + 1, count) &&
           is_complete(tree->right, 2 * index + 2, count);
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
    int node_count = count_nodes(tree);
    int index = 0;

    return is_complete(tree, index, node_count);
}
