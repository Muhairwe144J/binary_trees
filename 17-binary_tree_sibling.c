#include "binary_trees.h"

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !node->parent)
        return NULL;

    if (node->parent->left && node->parent->left != node)
        return (node->parent->left);

    if (node->parent->right && node->parent->right != node)
        return (node->parent->right);

    return NULL;
}
