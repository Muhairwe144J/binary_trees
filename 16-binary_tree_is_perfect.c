#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height == right_height)
    {
        if (!tree->left && !tree->right)
            return 1;

        if (tree->left && tree->right)
            return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
    }

    return 0;
}

int binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
