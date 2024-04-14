#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl_helper - Helper function to check if a binary tree is AVL.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value that a node can have.
 * @max: The maximum value that a node can have.
 *
 * Return: If the tree is AVL, return 1. Otherwise, return 0.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
    size_t left_height, right_height;
    int balance_factor;

    if (tree == NULL)
        return (1);

    /* Check if the current node's value is within the allowed range */
    if (tree->n < min || tree->n > max)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl_helper - Helper function to check if a binary tree is AVL.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value that a node can have.
 * @max: The maximum value that a node can have.
 *
 * Return: If the tree is AVL, return 1. Otherwise, return 0.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
    size_t left_height, right_height;
    int balance_factor;

    if (tree == NULL)
        return (1);

    /* Check if the current node's value is within the allowed range */
    if (tree->n < min || tree->n > max)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    /* Calculate the balance factor */
    balance_factor = left_height - right_height;

    /* Check if the balance factor is within -1, 0, or 1 */
    if (balance_factor < -1 || balance_factor > 1)
        return (0);

    /* Recursively check the left and right subtrees */
    return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
            binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is an AVL tree, return 1. Otherwise, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_avl_helper(tree, INT_MIN, INT_MAX));
}

